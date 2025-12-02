#!/usr/bin/python3
"""
This module reads log lines from stdin and computes statistics about HTTP
requests.
"""

import sys
import signal

def print_stats(total_size, status_counts):
    """Print statistics"""
    print("File size: {}".format(total_size))
    for status_code in sorted(status_counts.keys()):
        if status_counts[status_code] > 0:
            print("{}: {}".format(status_code, status_counts[status_code]))


def parse_line(line):
    """Parse a log line and return status code and file size"""
    parts = line.split()
    if len(parts) < 7:
        return None, None
    
    try:
        status_code = int(parts[-2])
        file_size = int(parts[-1])
        if '"GET /projects/260 HTTP/1.1"' not in line:
            return None, None
        return status_code, file_size
    except (ValueError, IndexError):
        return None, None


def main():
    """Main function"""
    total_size = 0
    status_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0
    
    def signal_handler(sig, frame):
        """Handle keyboard interrupt"""
        print_stats(total_size, status_counts)
        sys.exit(0)
    
    signal.signal(signal.SIGINT, signal_handler)
    
    try:
        for line in sys.stdin:
            status_code, file_size = parse_line(line)
            
            if status_code is not None and file_size is not None:
                if status_code in status_counts:
                    status_counts[status_code] += 1
                total_size += file_size
                line_count += 1
                
                if line_count % 10 == 0:
                    print_stats(total_size, status_counts)
        
        if line_count > 0 and line_count % 10 != 0:
            print_stats(total_size, status_counts)
    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        raise


if __name__ == "__main__":
    main()

