
int FUN_005762c0(undefined1 *param_1,uint param_2,undefined1 *param_3,int param_4)

{
  undefined1 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_4 == 0) {
    return 0;
  }
  if ((int)param_2 < 0) {
    uVar2 = CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]);
    while (uVar2 != 0) {
      if ((uVar2 < 0x100) && (1 < (uint)(param_4 - iVar4))) {
        if (param_3 != (undefined1 *)0x0) {
          *param_3 = (char)uVar2;
          param_3 = param_3 + 1;
        }
        iVar4 = iVar4 + 1;
      }
      uVar2 = CONCAT31(CONCAT21(CONCAT11(param_1[4],param_1[5]),param_1[6]),param_1[7]);
      param_1 = param_1 + 4;
    }
  }
  else {
    uVar2 = 0;
    if (param_2 != 0) {
      puVar1 = param_1 + 2;
      do {
        uVar2 = uVar2 + 1;
        uVar3 = CONCAT31(CONCAT21(CONCAT11(puVar1[-2],puVar1[-1]),*puVar1),puVar1[1]);
        if (uVar3 == 0) break;
        if ((uVar3 < 0x100) && (1 < (uint)(param_4 - iVar4))) {
          if (param_3 != (undefined1 *)0x0) {
            *param_3 = puVar1[1];
            param_3 = param_3 + 1;
          }
          iVar4 = iVar4 + 1;
        }
        puVar1 = puVar1 + 4;
      } while (uVar2 < param_2);
    }
  }
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = 0;
  }
  return iVar4 + 1;
}

