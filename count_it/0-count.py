#!/usr/bin/python3
"""
Module to count occurrences of keywords in hot posts
of a subreddit using Reddit API
"""
import requests


def count_words(subreddit, word_list, after=None, word_count=None):
    """
    Count occurrences of keywords in hot posts of a subreddit
    """
    if word_count is None:
        word_count = {}
        word_list = [w.lower() for w in word_list]

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    if after:
        url += f"?after={after}"

    headers = {
        'User-Agent': 'sarah/1.0'
    }

    try:
        response = requests.get(url, headers=headers, allow_redirects=False)
    except requests.RequestException:
        return

    if response.status_code != 200:
        return
    data = response.json()

    posts = data['data']['children']
    after_token = data['data']['after']

    for post in posts:
        title = post['data']['title']

        words_in_title = title.lower().split()

        for keyword in word_list:
            count = words_in_title.count(keyword)
            if keyword in word_count:
                word_count[keyword] += count
            else:
                word_count[keyword] = count

    if after_token is not None:
        return count_words(subreddit, word_list, after_token, word_count)

    filtered = {k: v for k, v in word_count.items() if v > 0}
    sorted_words = sorted(filtered.items(), key=lambda x: (-x[1], x[0]))

    for word, count in sorted_words:
        print(f"{word}: {count}")
