pub fn nth(n: u32) -> u32 {
    let mut primes: Vec<u32> = Vec::with_capacity(n as usize); // vector of the first knowm primes

    let mut is_prime = {
        |p_c: &u32| {
            if primes.iter().any(|p| p_c % *p == 0) {
                return false;
            }
            primes.push(*p_c);
            true
        }
    };

    (2..).filter(|c| is_prime(c)).nth(n as usize).unwrap()
}

pub fn main() {
	println!("{}", nth(20001));
}
