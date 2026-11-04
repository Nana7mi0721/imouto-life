
undefined4 FUN_0052cc60(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  if ((((DAT_00cc76d0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc76f8)) ||
     (((DAT_00cc7700 <= (int)(param_1 & 0xffff) ||
       (piVar2 = *(int **)(DAT_00cc76d4 + (param_1 & 0xffff) * 4), piVar2 == (int *)0x0)) ||
      ((*piVar2 * 0x10000 != (param_1 & 0x3ff0000) || (piVar2[4] != 0)))))) {
    return 0xffffffff;
  }
  if (param_4 == 0) {
    local_4 = FUN_0052caf0(param_2,param_3,0);
  }
  else {
    local_8 = 0;
    FUN_0057fb10(0,&local_8,param_1);
    FUN_0057fb10(0,&local_8,param_2);
    FUN_0057fb10(0,&local_8,param_3);
    puVar3 = (undefined4 *)FUN_0057fa80(local_8);
    if (puVar3 != (undefined4 *)0x0) {
      puVar3[3] = &LAB_0052cbb0;
      local_8 = 0;
      puVar1 = puVar3 + 4;
      FUN_0057fb10(puVar1,&local_8,param_1);
      FUN_0057fb10(puVar1,&local_8,param_2);
      FUN_0057fb10(puVar1,&local_8,param_3);
      iVar4 = FUN_00580290(puVar3);
      if (iVar4 < 0) {
        FUN_0056e1d0(puVar3);
        return local_4;
      }
      FUN_00580610(param_1,*puVar3);
      return 0;
    }
  }
  return local_4;
}

