
void __fastcall FUN_004c2ae0(int param_1)

{
  char cVar1;
  
  DAT_00a140b4 = (uint)(*(char *)(param_1 + 0x254) != '\0');
  DAT_00a140b8 = 0;
  *(int *)(param_1 + 0x278) = (*(int *)(param_1 + 0x278) + 1) % (*(int *)(param_1 + 0x27c) * 5);
  if (*(int *)(param_1 + 0x270) < 1) {
    FUN_004c2d50();
    if (*(char *)(param_1 + 0x254) == '\0') {
      cVar1 = operator!=<>(&DAT_00a13fc0,&DAT_007d0621);
      if (cVar1 == '\0') {
        if (*(int *)(param_1 + 0x25c) != 0) {
          *(undefined4 *)(param_1 + 0x25c) = 0;
          DAT_00a1405c = 0;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x254) = 1;
        DAT_00a1405c = 1;
        FUN_004c2e40();
        FUN_004c2ed0();
        *(undefined4 *)(param_1 + 0x25c) = 1;
      }
    }
    else if ((DAT_00a14090 == '\0') && (DAT_00a140b9 != '\0')) {
      FUN_004c1a20();
    }
    else if (*(char *)(param_1 + 0xe2) == '\0') {
      cVar1 = FUN_004c2d10();
      if (cVar1 != '\0') {
        DAT_00a140b8 = 1;
        *(undefined1 *)(param_1 + 0x256) = 1;
        if (DAT_00a14090 == '\0') {
          if (((DAT_00a14670 != '\0') || (DAT_00a14671 != '\0')) ||
             ((DAT_00a18af0 == 1 && (DAT_00a1461d != '\0')))) {
            FUN_004c1a20();
          }
          if (*(char *)(param_1 + 0xe3) != '\0') {
            FUN_004c1a20();
          }
        }
        else if ((DAT_00a14090 != '\0') &&
                (*(undefined1 *)(param_1 + 0x256) = 0, DAT_00a14091 != '\0')) {
          FUN_004c1a20();
        }
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x256) = 1;
      if (((DAT_00a14670 != '\0') || (DAT_00a14671 != '\0')) ||
         ((DAT_00a18af0 == 1 && (DAT_00a1461d != '\0')))) {
        *(undefined1 *)(param_1 + 0xe2) = 0;
      }
    }
  }
  else {
    *(int *)(param_1 + 0x270) = *(int *)(param_1 + 0x270) + -1;
    if (*(int *)(param_1 + 0x270) == 0) {
      FUN_004c2ed0();
    }
  }
  return;
}

