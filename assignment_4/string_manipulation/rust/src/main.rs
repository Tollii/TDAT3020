fn main() {

   let mut line = String::new();
   println!("Enter a string:");
   let _ = std::io::stdin().read_line(&mut line).unwrap();

   let res = manipulate_string(&line);
   println!("{}", res);

}



fn manipulate_string(x: &str) -> String {
    return x.replace("&", "&amp").replace("<", "&lt").replace(">", "&gt");
}
