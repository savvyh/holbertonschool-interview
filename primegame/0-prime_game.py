#!/usr/bin/python3


def is_prime(number):
    """Check if a number is prime"""
    if number < 2:
        return False
    if number == 2:
        return True
    if number % 2 == 0:
        return False
    for index in range(3, int(number ** 0.5) + 1, 2):
        if number % index == 0:
            return False
    return True


def get_primes(numbers):
    """Get the available primes in the set"""
    primes = []
    for number in numbers:
        if is_prime(number):
            primes.append(number)
    return primes


def remove_prime(numbers, prime_number):
    """Remove a prime and all its multiples from the set"""
    result = []
    for number in numbers:
        if number % prime_number != 0:
            result.append(number)
    return tuple(result)


def can_win(numbers, winning_results):
    """Determine if the current player can win"""
    if not numbers:
        return False
    
    if numbers in winning_results:
        return winning_results[numbers]
    
    primes = get_primes(numbers)
    
    if not primes:
        winning_results[numbers] = False
        return False
    
    for prime_number in primes:
        new_numbers = remove_prime(numbers, prime_number)
        if not can_win(new_numbers, winning_results):
            winning_results[numbers] = True
            return True
    
    winning_results[numbers] = False
    return False


def isWinner(x, nums):
    """Determine the winner of the game"""
    if not nums or x == 0:
        return None
    
    maria_wins = 0
    ben_wins = 0
    winning_results = {}
    
    for n in nums:
        numbers = tuple(range(1, n + 1))
        if can_win(numbers, winning_results):
            maria_wins += 1
        else:
            ben_wins += 1
    
    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
