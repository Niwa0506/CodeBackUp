class Student {
    String id;    // 蟄ｦ邀咲分蜿ｷ
    String name;  // 蜷榊燕
    int grade;    // 謌千ｸｾ

   private void print() {
      System.out.println("ID   : "+id);  
      System.out.println("Name : "+name);
      System.out.println("Grade: "+grade);
    }
}

class main2 {
  public static void main(String argv[]){
    Student st  = new Student();
    Student st2 = new Student();
    st.id="01110";    st2.id="01111";
    st.name="Suzuki"; st2.name="Yamada";
    st.grade=100;     st2.grade=80;

    st.print();       
    st2.print();
  }
}