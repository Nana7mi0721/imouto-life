
void __thiscall FUN_0062f460(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  if ((*(byte *)(param_2 + 200) & 3) == 0) {
    FUN_0063bb60(param_1 + 0x36);
  }
  if (*(int *)(param_2 + 0xc0) != 0) {
    if ((*(byte *)(param_2 + 200) & 1) == 0) {
      iVar2 = param_1[0x32];
      if (iVar2 == param_1[0x33]) {
        iVar6 = iVar2 * 2;
        if (iVar2 == 0) {
          iVar6 = 1;
        }
        if (param_1[0x33] < iVar6) {
          if (iVar6 == 0) {
            puVar3 = (undefined4 *)0x0;
          }
          else {
            puVar3 = (undefined4 *)FUN_00646b30(iVar6 * 4,0x10);
          }
          iVar2 = param_1[0x32];
          iVar4 = 0;
          if (0 < iVar2) {
            puVar5 = puVar3;
            do {
              if (puVar5 != (undefined4 *)0x0) {
                *puVar5 = *(undefined4 *)(param_1[0x34] + iVar4 * 4);
              }
              iVar4 = iVar4 + 1;
              puVar5 = puVar5 + 1;
            } while (iVar4 < iVar2);
          }
          if (param_1[0x34] != 0) {
            if ((char)param_1[0x35] != '\0') {
              FUN_00646b80(param_1[0x34]);
            }
            param_1[0x34] = 0;
          }
          param_1[0x34] = (int)puVar3;
          *(undefined1 *)(param_1 + 0x35) = 1;
          param_1[0x33] = iVar6;
        }
      }
      piVar1 = (int *)(param_1[0x34] + param_1[0x32] * 4);
      if (piVar1 != (int *)0x0) {
        *piVar1 = param_2;
      }
      param_1[0x32] = param_1[0x32] + 1;
    }
    else {
      FUN_006105d0(2);
    }
    (**(code **)(*param_1 + 0x10))(param_2,param_3,param_4);
  }
  return;
}

