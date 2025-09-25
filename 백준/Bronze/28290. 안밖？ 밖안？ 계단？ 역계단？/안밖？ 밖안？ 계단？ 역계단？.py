def main():
    s = input().strip()
    
    patterns = {
        "in-out": ["fdsajkl;", "jkl;fdsa"],
        "out-in": ["asdf;lkj", ";lkjasdf"],
        "stairs": ["asdfjkl;"],
        "reverse": [";lkjfdsa"]
    }

    for name, arr in patterns.items():
        if s in arr:
            print(name)
            return
    print("molu")

if __name__ == "__main__":
    main()