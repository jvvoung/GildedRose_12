# Gilded Rose

Gilded Rose 는 게임 "World of Warcraft"에 나오는 여관 이름입니다.  
아이템은 퀄리티 속성을 가지고 있으며, 예외 사항이 있는 아이템들이 있습니다.  
- 아이템은 [아이템 이름, 퀄리티, 유통기한]의 속성을 가집니다.  
- 아이템의 퀄리티는 0 이상이고 아이템의 퀄리티는 하루가 지날 때마다 1씩 줄어듭니다.  
- 유통 기한이 지난 아이템의 퀄리티는 2배의 속도로 떨어집니다.  
- 퀄리티는 최대값이 50입니다.  

### Aged Brie, Backstage Pass, Sulfuras 의 예외적 규칙  

- Aged Brie는 하루가 지날 때마다 퀄리티가 1씩 증가합니다.  
- 유통기한이 지나면 퀄리티가 2씩 증가합니다.  
- Backstage Pass 는 유통기한(콘서트일)이 다가올수록 퀄리티가 증가합니다.  
  유통기한이 11일 이상일 때는 1, 10일 이하일 때는 2, 5일 이하일 때는 3씩 증가하지만  
  콘서트 날이 지나면 퀄리티는 0이 됩니다.  
- Sulfuras의 퀄리티는 변화가 없습니다.  
  
---------------------------------------------------------  
## 실습 목적 :  테스트 코드 작성을 통한 legacy code 이해

### 프로젝트 구조 (C++)

```
cpp/
├── CMakeLists.txt          # CMake 빌드 설정 (Google Test 자동 다운로드)
├── include/
│   ├── Item.h              # Item 클래스 (수정 불가)
│   └── GildedRose.h        # GildedRose 클래스 헤더
├── src/
│   └── GildedRose.cpp      # updateQuality() 구현
└── test/
    └── GildedRoseTest.cpp  # Google Test 기반 테스트
```

### 빌드 및 테스트 실행

```bash
cd cpp
cmake -B build
cmake --build build
ctest --test-dir build
```

### GildedRoseTest.cpp : failed test 수정
- updateQuality() 의 test case를 추가 작성해 보세요.
- unit test 내용 : 문서상에 나타난 동작들 확인

### unit test VS golden-master test 비교

### TO-DO LIST (12 Steps)

1. **테스트 먼저** — Google Test로 회귀 테스트 작성 (일반·기한·하한/상한·특수 아이템·경계값 등).
2. **코드 정리** — 매직 스트링 상수 추출, `items[i]` → `Item&` 변수 추출, 불필요 코드 제거.
3. **조건 분리** — if 반전, else-if 병합, 조건 단순화(긍정 조건 우선).
4. **메서드 추출** — 타입별 `updateQuality*()` 및 `updateSellIn()` 등으로 분리.
5. **클래스 분리** — `AgedBrieItem`, `BackstagePassItem`, `SulfurasItem`, `NormalItem` 등 (`Item` 클래스는 수정하지 않음).
6. **추상화** — `GildedRoseItem` 추상 기반 클래스 + 다형성, Factory로 생성.
7. **기능 추가** — 새 아이템 카테고리(예: F&B, Conjured)는 새 클래스 + Factory 최소 변경으로 추가.
8. **변수 선언 분리** — Split declaration으로 분기마다 중복 선언 정리.
9. **중복 제거** — 루프 본문을 `createItem` → `updateQuality` → `updateSellIn` 패턴으로 통일.
10. **Factory 메서드 추출** — `createItem` / `getItem` 등으로 객체 생성 책임 한곳에 모음.
11. **메서드/구조 정리** — 필요 시 보조 메서드 추출로 가독성·응집도 보완.
12. **Inline** — 불필요한 임시 변수 인라인 등으로 `updateQuality()` 본문을 짧게 마무리.
