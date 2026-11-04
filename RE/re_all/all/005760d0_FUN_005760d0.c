
int FUN_005760d0(uint *param_1,uint param_2,undefined1 *param_3,int param_4)

{
  undefined2 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_4 == 0) {
    return 0;
  }
  if ((int)param_2 < 0) {
    uVar3 = *param_1;
    while (uVar3 != 0) {
      param_1 = param_1 + 1;
      if ((uVar3 < 0x100) && (1 < (uint)(param_4 - iVar4))) {
        if (param_3 != (undefined1 *)0x0) {
          *param_3 = (char)uVar3;
          param_3 = param_3 + 1;
        }
        iVar4 = iVar4 + 1;
      }
      uVar3 = *param_1;
    }
  }
  else {
    uVar3 = 0;
    if (param_2 != 0) {
      puVar1 = (undefined2 *)((int)param_1 + 2);
      do {
        uVar3 = uVar3 + 1;
        uVar2 = CONCAT31(CONCAT21(*puVar1,*(undefined1 *)((int)puVar1 + -1)),
                         *(undefined1 *)(puVar1 + -1));
        if (uVar2 == 0) break;
        if ((uVar2 < 0x100) && (1 < (uint)(param_4 - iVar4))) {
          if (param_3 != (undefined1 *)0x0) {
            *param_3 = *(undefined1 *)(puVar1 + -1);
            param_3 = param_3 + 1;
          }
          iVar4 = iVar4 + 1;
        }
        puVar1 = puVar1 + 2;
      } while (uVar3 < param_2);
    }
  }
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = 0;
  }
  return iVar4 + 1;
}

