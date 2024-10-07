

fun myFunc(){
    println("Hello i am function")
}

fun myName(fname : String, age : Int){ // Chỉ cần lưu ý rằng bạn phải chỉ định loại của từng tham số (Int, String, v.v.).
//    println(fname + "Pham")
    println("$fname Pham $age tuoi")
}

fun myNums(x : Int, y : Int) : Int{ // Để trả về một giá trị, hãy sử dụng return từ khóa và chỉ định kiểu trả về sau dấu ngoặc đơn của hàm
    return x + y;
}

fun Nums(x : Int, y : Int) = x + y  // ngắn gọn hơn


fun main(){
    myFunc()
    myName("Long", 19)
    myName("Cheems", 18)
    myName("Nakano", 19)
    println(myNums(5,14))
    println(Nums(5,14))
}