
//     int a =10;
//     int funcAdd(int x, int y){
//         return x+y+a;
//     }
// }
// public class practice{
//  public static void main(String[] args) {
//     int x= 3; 
//     int y= 6;
//     int r;

//     classA cal  = new classA();
//     r =  cal.funcAdd(x,y);
//     System.out.println(r);
//  }
// }

// class ClassA{
//     ClassA() {
//         System.out.print('A');
//         this.prn();
//         //this.prn -> class b 의 prn을 가르킨다.
//     }
//     void prn(){
//         System.out.print('B');
//     }
// }
// // ** extends는 상속을 의미한다 즉 calssb 는 classa를 상속 받는다.
// class ClassB extends ClassA{
//     ClassB(){
//         super();
//         // classa를 호출하라 - 상속된 classa를 먼저 호출
//         System.out.print('D');
//     }
//     void prn(){
//         System.out.print('E');
//     }
//     void prn(int x){
//         System.out.print(x);
//     }
// }
// //AE
// public class practice{
//     public static void main(String[] args) {
//         int x =7;
//         ClassB cal = new ClassB();
//         cal.prn(x);
//     }
// }
// // A  → ClassA 생성자에서
// // E  → this.prn()이 ClassB의 오버라이딩된 메서드 실행
// // D  → ClassB 생성자에서
// // 7  → cal.prn(x)


// //추상클래스 abstract
// abstract class Animal {
//     String a = "is animal";
//     abstract void look();
//     void show(){
//         System.out.println("zoo");
//     }
// }

// class Chicken extends Animal{
//     Chicken(){
//         look();
//     }
//     void look(){
//         System.out.println("chicken"+a);
//     }

//     void display(){

//         System.out.println("two wings");

//     }
// }

// public class practice{
//     public static void main(String[] args) {
        
//         Animal a = new Chicken();
//         a.show();
//     }


// }

