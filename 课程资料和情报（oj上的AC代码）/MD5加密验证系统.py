import hashlib
def calculate_md5(text):
    md5 = hashlib.md5()
    md5.update(text.encode())
    return md5.hexdigest()
def compare_md5(text1, text2):
    return calculate_md5(text1) == calculate_md5(text2)
for i in range(int(input())):
    print("Yes" if compare_md5(input(),input()) else "No")
