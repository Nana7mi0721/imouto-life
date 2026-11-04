
undefined4 FUN_0065a290(undefined4 param_1,undefined2 *param_2,uint param_3,int *param_4)

{
  undefined2 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  puVar1 = param_2;
  iVar3 = FUN_00659030(param_1,param_2,&param_2);
  uVar2 = param_3;
  if (iVar3 != 0) {
    iVar4 = FUN_00653820(param_1,*puVar1);
    if (iVar4 == 0) {
      pcVar5 = s_unknown_tagname_00a09ed0;
    }
    else {
      pcVar5 = *(char **)(iVar4 + 0x1c);
    }
    FUN_00655980(param_1,iVar3,"TIFFFetchStripThing",pcVar5,0);
    return 0;
  }
  if ((*(uint *)(puVar1 + 4) == param_3) && (*(int *)(puVar1 + 6) == 0)) {
    *param_4 = (int)param_2;
    return 1;
  }
  iVar3 = FUN_00650c00(param_1,param_3,8,s_for_strip_array_00a0a5d4);
  if (iVar3 == 0) {
    FUN_006507e0(param_2);
    return 0;
  }
  if ((*(int *)(puVar1 + 6) == 0) && (*(uint *)(puVar1 + 4) < uVar2)) {
    FUN_00650840(iVar3,param_2,*(int *)(puVar1 + 4) << 3);
    FUN_00650810(iVar3 + *(int *)(puVar1 + 4) * 8,0,(uVar2 - *(int *)(puVar1 + 4)) * 8);
    FUN_006507e0(param_2);
    *param_4 = iVar3;
    return 1;
  }
  FUN_00650840(iVar3,param_2,uVar2 * 8);
  FUN_006507e0(param_2);
  *param_4 = iVar3;
  return 1;
}

