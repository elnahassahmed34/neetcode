from collections import defaultdict

def group_anagrams(strs):
    anagram_dict = defaultdict(list)
    
    for s in strs:
        sorted_str = ''.join(sorted(s))
        anagram_dict[sorted_str].append(s)
    
    return list(anagram_dict.values())

# Example usage
strs1 = ["act", "pots", "tops", "cat", "stop", "hat"]
result1 = group_anagrams(strs1)
print("Grouped Anagrams:", result1)

strs2 = ["x"]
result2 = group_anagrams(strs2)
print("Grouped Anagrams:", result2)

strs3 = [""]
result3 = group_anagrams(strs3)
print("Grouped Anagrams:", result3)
