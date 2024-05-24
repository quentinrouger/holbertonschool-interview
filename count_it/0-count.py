#!/usr/bin/python3
"""
Write a recursive function that queries the Reddit API.
"""
import requests
import sys
import collections

def count_words(subreddit, word_list, after=None, word_count=None):
    """
    Recursively counts occurrences of specified keywords in titles of 
    hot articles from a given subreddit.

    Args:
        subreddit (str): The name of the subreddit to query.
        word_list (list): A list of keywords to count in the titles.
        after (str, optional): The 'after' parameter for Reddit API pagination.
        Defaults to None.
        word_count (dict, optional): A dictionary to keep the count of
        each keyword. Defaults to None.

    Returns:
        None: The function prints the word counts sorted by count and
        alphabetically if counts are the same.
    """
    if word_count is None:
        word_count = collections.defaultdict(int)
    headers = {'User-Agent': 'Python:count_words:v1.0 (by /u/yourusername)'}
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    params = {'limit': 100}
    if after:
        params['after'] = after

    response = requests.get(url, headers=headers, params=params, allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json()

    for article in data['data']['children']:
        title = article['data']['title']
        words = title.split()
        for word in words:
            cleaned_word = ''.join(filter(str.isalnum, word)).lower()
            if cleaned_word in word_list:
                word_count[cleaned_word] += 1

    if data['data']['after']:
        count_words(subreddit, word_list, data['data']['after'], word_count)

    if after is None:
        sorted_word_count = sorted(word_count.items(), key=lambda item: (-item[1], item[0]))
        for word, count in sorted_word_count:
            if count > 0:
                print(f"{word}: {count}")

if __name__ == '__main__':
    """
    Main entry point for the script. It expects two command line arguments:
    a subreddit and a list of keywords.

    Usage:
        python3 script_name.py <subreddit> '<list of keywords>'
    
    Example:
        python3 script_name.py programming 'python java javascript'
    """
    if len(sys.argv) < 3:
        print("Usage: {} <subreddit> <list of keywords>".format(sys.argv[0]))
        print("Ex: {} programming 'python java javascript'".format(sys.argv[0]))
    else:
        subreddit = sys.argv[1]
        word_list = [word.lower() for word in sys.argv[2].split()]
        count_words(subreddit, word_list)
