

https://github.com/hyeonsukk615/OpenCV_final1/assets/171308920/2ab2a1aa-15cf-496c-892a-8a96f6fc1969


필기체 숫자 입력창 500 x 500 윈도우에 마우스로 입력

저장기능 저장버튼 클릭시 콘솔창에서 파일이름 입력 후 현재
입력창의 영상을 프로젝트 폴더에 파일로 저장

삭제기능 삭제버튼 클릭시 숫자 입력창의 내용을 삭제

불러오기 기능 불러오기 버튼 클릭시 불러올 영상파일명 입력 후
영상을 불러와 입력창에 출력

인식기능 인식버튼 클릭시 편집창의 숫자를 인식하고 인식결과를
콘솔창에 출력함

종료기능 종료버튼 클릭시 프로그램 종료

1. 초기화 및 윈도우 설정 500x700 크기의 흰색 캔버스를 생성합니다.
"windows"라는 이름의 윈도우를 생성합니다. 마우스 콜백 함수를 설정하여 마우스 이벤트를 처리합니다.

2.메인 루프 무한 루프에서 Set(canvas);를 호출하여 버튼과 캔버스를 화면에 표시합니다.

3. 마우스 이벤트 처리 (onMouse 함수) 

마우스 왼쪽 버튼을 눌렀을 때.
입력 영역(500x500) 내에서 드로잉 모드를 활성화합니다.
버튼 영역(500 이상)에서 적절한 작업(저장, 불러오기, 삭제, 실행, 종료)을 수행합니다.

마우스 이동 시. 로잉 모드가 활성화된 경우, 선을 그립니다.

마우스 왼쪽 버튼을 뗐을 때. 드로잉 모드를 비활성화합니다.

4. 인터페이스 설정 (Set 함수): 캔버스를 표시합니다.
버튼 영역을 정의하고 사각형과 텍스트를 그려 사용자 인터페이스를 설정합니다.
Save, Load, Clear, Run, Exit 버튼을 설정합니다.

5. 캔버스 지우기 (Clear 함수):Clear 버튼이 클릭되었을 때, 캔버스를 초기 상태로 되돌립니다.
콘솔창에 "windows Clear" 메시지를 출력합니다.

6.각 버튼의 기능
저장 기능(save) Save 버튼 클릭 시, 콘솔창에서 파일명을 입력 받아 현재 입력창의 영상을 파일로 저장합니다.
저장할 영상은 3채널 컬러 영상으로 저장됩니다.

삭제 기능(Clear)Clear 버튼 클릭 시, 입력창의 내용을 삭제합니다.
Rect contains 함수를 사용하여 클릭된 영역을 확인하고 마우스 이벤트로 처리합니다.

불러오기 기능(load)Load 버튼 클릭 시, 콘솔창에서 파일명을 입력 받아 영상을 불러와 입력창에 출력합니다.

종료기능(Exit) Exit 버튼 클릭 시, 프로그램을 종료합니다.