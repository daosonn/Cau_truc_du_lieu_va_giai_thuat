import math

def is_prime(n):
    """Kiểm tra số nguyên tố."""
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def generate_blum_numbers(N):
    """Tạo ra các số Blum nhỏ hơn N."""
    primes = [p for p in range(3, N) if is_prime(p) and p % 4 == 3]
    blum_numbers = set()

    for i in range(len(primes)):
        for j in range(i + 1, len(primes)):
            blum = primes[i] * primes[j]
            if blum < N:
                blum_numbers.add(blum)
            else:
                break
    return sorted(blum_numbers)

def find_blum_pairs(blum_numbers, N):
    """Tìm các cặp số Blum"""
    blum_set = set(blum_numbers)
    pairs = []

    for i in range(len(blum_numbers)):
        for j in range(i, len(blum_numbers)):
            total = blum_numbers[i] + blum_numbers[j]
            if total < N and total in blum_set:
                pairs.append((blum_numbers[i], blum_numbers[j]))

    return pairs

def check_blum_existence(blum_numbers, M):
    return M in blum_numbers

if __name__ == "__main__":
    N = int(input("Nhap N:"))
    M = int(input("Nhap M:"))

    # Tạo ra các số Blum nhỏ hơn N
    blum_numbers = generate_blum_numbers(N)
    print("Dãy số Blum:", blum_numbers)

    # Tìm các cặp số Blum có tổng cũng là số Blum
    blum_pairs = find_blum_pairs(blum_numbers, N)
    print("Các cặp số Blum có tổng cũng là số Blum:")
    for pair in blum_pairs:
        print(pair)

    # Kiểm tra sự tồn tại của số Blum M
    if check_blum_existence(blum_numbers, M):
        print(f"Số {M} là một số Blum trong dãy.")
    else:
        print(f"Số {M} không phải là số Blum trong dãy.")