
int FUN_00575000(int *param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 *puVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = 0;
  if (param_4 < 4) {
    return 0;
  }
  if ((int)param_2 < 0) {
    iVar3 = *param_1;
    while (iVar3 != 0) {
      param_1 = param_1 + 1;
      if (7 < param_4 - iVar7) {
        if (param_3 != (undefined4 *)0x0) {
          *(char *)param_3 = (char)((uint)iVar3 >> 0x18);
          *(char *)((int)param_3 + 1) = (char)((uint)iVar3 >> 0x10);
          *(char *)((int)param_3 + 2) = (char)((uint)iVar3 >> 8);
          *(char *)((int)param_3 + 3) = (char)iVar3;
          param_3 = param_3 + 1;
        }
        iVar7 = iVar7 + 4;
      }
      iVar3 = *param_1;
    }
  }
  else {
    uVar6 = 0;
    if (param_2 != 0) {
      puVar5 = (undefined2 *)((int)param_1 + 2);
      do {
        uVar1 = *(undefined1 *)((int)puVar5 + -1);
        uVar6 = uVar6 + 1;
        uVar4 = *puVar5;
        uVar2 = *(undefined1 *)(puVar5 + -1);
        if (CONCAT31(CONCAT21(uVar4,uVar1),uVar2) == 0) break;
        if (7 < param_4 - iVar7) {
          if (param_3 != (undefined4 *)0x0) {
            *(char *)param_3 = (char)((ushort)uVar4 >> 8);
            *(char *)((int)param_3 + 1) = (char)uVar4;
            *(undefined1 *)((int)param_3 + 2) = uVar1;
            *(undefined1 *)((int)param_3 + 3) = uVar2;
            param_3 = param_3 + 1;
          }
          iVar7 = iVar7 + 4;
        }
        puVar5 = puVar5 + 2;
      } while (uVar6 < param_2);
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  return iVar7 + 4;
}

