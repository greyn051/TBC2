/*
## 8.3 입출력 방향 재지정(Redirection)
*/

// 출력 redirection

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

    printf("I love apple.\n");

    return 0;
}

/*
D:\>cd D:\dev\repository\C\Chapter_3\Chapter_3\Debug

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>dir
D 드라이브의 볼륨: 새 볼륨
볼륨 일련 번호: 0C27-6DC3

D:\dev\repository\C\Chapter_3\Chapter_3\Debug 디렉터리

2021-01-28 오후 05:13 <DIR> .
2021-01-28 오후 05:13 <DIR> ..
2021-02-01 오전 11:35 39,936 Lecture_3_6.exe
2021-02-01 오전 11:35 642,772 Lecture_3_6.ilk
2021-02-01 오전 11:35 593,920 Lecture_3_6.pdb
3개 파일 1,276,628 바이트
2개 디렉터리 207,875,551,232 바이트 남음

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>Lecture3_6.exe
'Lecture3_6.exe'은(는) 내부 또는 외부 명령, 실행할 수 있는 프로그램, 또는
배치 파일이 아닙니다.

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>Lecture_3_6.exe
I love apple.

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>Lecture_3_6.exe > output.txt

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>output.txt

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>explorer .

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>notepad output.txt
*/


/*********************************************************
*********************************************************/


// 입력 redirection

int main() {

    char str[100];
    scanf("%s", str);
    printf("I love %s\n", str);

    return 0;
}

/*
D:\dev\repository\C\Chapter_3\Chapter_3\Debug>Lecture_3_6 < input.txt
I love Melon.

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>Lecture_3_6<input.txt>output.txt
*/


/*********************************************************
*********************************************************/


// 기존 output에 내용 추가

/*
D:\dev\repository\C\Chapter_3\Chapter_3\Debug>Lecture_3_6>>output.txt
Banana
*/


/*********************************************************
*********************************************************/


// 좀 더 복잡하게

/*
test.exe의 결과가
Lecture3.exe로 파이프를 통해 흘러가게 하기
*/

// - test.exe

  int main() {

      printf("Programming");

      return 0;
  }


// - Lecture_3_6.exe

  int main() {

      char str[100];
      scanf("%s", str);
      printf("I love %s\n", str);

      return 0;
  }

/*
D:\dev\repository\C\Chapter_3\Chapter_3\Debug>copy Lecture_3_6.exe test.exe
1개 파일이 복사되었습니다.

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>test.exe
Programming
D:\dev\repository\C\Chapter_3\Chapter_3\Debug>test.exe | Lecture_3_6.exe
I love Programming
*/
