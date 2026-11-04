
void FUN_00678e10(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,char *param_7,undefined4 *param_8)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  undefined1 local_5c [4];
  undefined1 local_58 [4];
  undefined1 local_54;
  undefined1 local_53;
  undefined1 local_50 [80];
  
  if (3 < param_5) {
    FUN_00668620(param_1,s_Unrecognized_equation_type_for_p_00a0d8f4);
  }
  iVar2 = FUN_006782a0(param_1,param_2,local_50);
  if (iVar2 == 0) {
    FUN_00668620(param_1,s_pCAL__invalid_keyword_00a0d8dc);
  }
  uVar5 = 0xffffffff;
  pcVar9 = param_7;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  iVar8 = (~uVar5 - 1) + (uint)(param_6 != 0);
  param_2 = iVar8 + 10 + iVar2 + 1;
  piVar3 = (int *)FUN_0066caf0(param_1,param_6 * 4);
  iVar7 = 0;
  if (0 < param_6) {
    piVar6 = piVar3;
    do {
      uVar5 = 0xffffffff;
      pcVar9 = *(char **)(((int)param_8 - (int)piVar3) + (int)piVar6);
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      iVar4 = (uint)(iVar7 != param_6 + -1) + (~uVar5 - 1);
      param_2 = param_2 + iVar4;
      *piVar6 = iVar4;
      iVar7 = iVar7 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar7 < param_6);
  }
  FUN_00677300(param_1,0x7043414c,param_2);
  FUN_00677370(param_1,local_50,iVar2 + 1);
  FUN_006696b0(local_5c,param_3);
  FUN_006696b0(local_58,param_4);
  local_54 = (undefined1)param_5;
  local_53 = (undefined1)param_6;
  FUN_00677370(param_1,local_5c,10);
  FUN_00677370(param_1,param_7,iVar8);
  if (0 < param_6) {
    iVar2 = (int)piVar3 - (int)param_8;
    do {
      FUN_00677370(param_1,*param_8,*(undefined4 *)(iVar2 + (int)param_8));
      param_8 = param_8 + 1;
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  FUN_0066cb60(param_1,piVar3);
  FUN_006773b0(param_1);
  return;
}

