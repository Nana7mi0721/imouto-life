
undefined4
FUN_00560370(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,
            undefined4 param_5,undefined4 param_6,int param_7)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  iVar1 = FUN_0057e0e0();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  if (param_7 == 0) {
    if ((((DAT_00cc4db0 != 0) && (-1 < (int)param_4)) && ((param_4 & 0x7c000000) == DAT_00cc4dd8))
       && ((((int)(param_4 & 0xffff) < DAT_00cc4de0 &&
            (piVar4 = *(int **)(DAT_00cc4db4 + (param_4 & 0xffff) * 4), piVar4 != (int *)0x0)) &&
           ((*piVar4 * 0x10000 == (param_4 & 0x3ff0000) && (piVar4[4] == 0)))))) goto LAB_00560439;
  }
  else if (((DAT_00cc4db0 != 0) && (-1 < (int)param_4)) &&
          (((param_4 & 0x7c000000) == DAT_00cc4dd8 &&
           ((((int)(param_4 & 0xffff) < DAT_00cc4de0 &&
             (piVar4 = *(int **)(DAT_00cc4db4 + (param_4 & 0xffff) * 4), piVar4 != (int *)0x0)) &&
            (*piVar4 * 0x10000 == (param_4 & 0x3ff0000))))))) {
LAB_00560439:
    iVar1 = thunk_FUN_00572540(param_2,0,1,0);
    if (iVar1 == 0) {
      FUN_0056bc50(L"Sound File Open Error : %s \n",param_2);
      return 0xffffffff;
    }
    local_4 = iVar1;
    puVar2 = (undefined4 *)FUN_0052c790();
    local_1c = *puVar2;
    local_18 = puVar2[1];
    local_14 = puVar2[2];
    local_10 = puVar2[3];
    local_c = puVar2[4];
    local_8 = puVar2[5];
    iVar3 = FUN_0055fb70(param_1,&local_1c,param_3,param_4,param_5,&local_20,param_6,param_7);
    if (iVar3 == -1) {
      thunk_FUN_00571d20(iVar1);
      FUN_0056bc50(L"Sound File Setup Error : %s \n",param_2);
      return 0xffffffff;
    }
    if (local_20 == 1) {
      thunk_FUN_00571d20(iVar1);
    }
    *(undefined1 *)(piVar4[0x92d] + 0x24af + (int)piVar4) = 1;
    return 0;
  }
  return 0xffffffff;
}

