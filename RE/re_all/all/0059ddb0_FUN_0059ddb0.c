
undefined4
FUN_0059ddb0(int param_1,uint param_2,uint param_3,uint param_4,int param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar2 = 0;
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if (*(char *)(*(int *)(param_1 + 0x4c) + 0xb) == '\0') {
    return 2;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  iVar1 = FUN_005d35f0();
  if ((iVar1 != 0) && (DAT_00e79688 != 0)) {
    FUN_005d3950();
    DAT_00e79688 = 0;
  }
  if (0 < *(int *)(param_1 + 0x88)) {
    piVar3 = (int *)(param_1 + 0x9c);
    do {
      local_10 = *piVar3;
      local_c = piVar3[1];
      local_8 = piVar3[4] + local_10;
      local_4 = piVar3[5] + local_c;
      FUN_005d5950(*(undefined4 *)(*(int *)piVar3[0x19] + 4),&local_10,
                   ((param_5 << 8 | param_2) << 8 | param_3) << 8 | param_4,param_6);
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 0x1e;
    } while (iVar2 < *(int *)(param_1 + 0x88));
  }
  return 0;
}

