
int FUN_00575410(undefined1 *param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  
  iVar6 = 0;
  if (param_4 < 4) {
    return 0;
  }
  if ((int)param_2 < 0) {
    iVar4 = CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]);
    while (iVar4 != 0) {
      if (7 < param_4 - iVar6) {
        if (param_3 != (undefined4 *)0x0) {
          *(char *)param_3 = (char)iVar4;
          *(char *)((int)param_3 + 1) = (char)((uint)iVar4 >> 8);
          *(char *)((int)param_3 + 2) = (char)((uint)iVar4 >> 0x10);
          *(char *)((int)param_3 + 3) = (char)((uint)iVar4 >> 0x18);
          param_3 = param_3 + 1;
        }
        iVar6 = iVar6 + 4;
      }
      iVar4 = CONCAT31(CONCAT21(CONCAT11(param_1[4],param_1[5]),param_1[6]),param_1[7]);
      param_1 = param_1 + 4;
    }
  }
  else {
    uVar7 = 0;
    if (param_2 != 0) {
      puVar5 = param_1 + 2;
      do {
        uVar1 = *puVar5;
        uVar2 = puVar5[-2];
        uVar7 = uVar7 + 1;
        uVar3 = puVar5[-1];
        if (CONCAT31(CONCAT21(CONCAT11(uVar2,uVar3),uVar1),puVar5[1]) == 0) break;
        if (7 < param_4 - iVar6) {
          if (param_3 != (undefined4 *)0x0) {
            *(undefined1 *)param_3 = puVar5[1];
            *(undefined1 *)((int)param_3 + 1) = uVar1;
            *(undefined1 *)((int)param_3 + 2) = uVar3;
            *(undefined1 *)((int)param_3 + 3) = uVar2;
            param_3 = param_3 + 1;
          }
          iVar6 = iVar6 + 4;
        }
        puVar5 = puVar5 + 4;
      } while (uVar7 < param_2);
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  return iVar6 + 4;
}

