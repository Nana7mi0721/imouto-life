
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0052b680(uint param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  float10 fVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [12];
  
  if ((((DAT_00cc79c0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc79e8)) ||
     (((DAT_00cc79f0 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc79c4 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  piVar3 = (int *)FUN_00586310(&local_18,param_2,param_3,param_4);
  local_24 = *piVar3;
  local_3c = 0;
  local_20 = piVar3[1];
  local_1c = piVar3[2];
  local_38 = 0x3f800000;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0x3f800000;
  local_28 = 0;
  piVar3 = (int *)FUN_00514ce0(&local_18,&local_30,&local_24);
  iVar7 = *piVar3;
  iVar5 = piVar3[1];
  iVar6 = piVar3[2];
  local_3c = iVar7;
  local_38 = iVar5;
  local_34 = iVar6;
  fVar8 = (float10)FUN_00514d20(&local_3c);
  fVar2 = (float10)_DAT_007d5348;
  if ((!NAN(fVar8) && !NAN(fVar2)) && fVar8 < fVar2 != (fVar8 == fVar2)) {
    local_18 = 0x3f800000;
    local_14 = 0;
    local_30 = 0x3f800000;
    local_10 = 0;
    local_2c = 0;
    local_28 = 0;
    piVar3 = (int *)FUN_00514ce0(&local_18,&local_30,&local_24);
    iVar7 = *piVar3;
    iVar5 = piVar3[1];
    iVar6 = piVar3[2];
    local_3c = iVar7;
    local_38 = iVar5;
    local_34 = iVar6;
  }
  puVar4 = (undefined4 *)FUN_00514ce0(&local_18,&local_24,&local_3c);
  piVar3 = (int *)FUN_00586310(local_c,*puVar4,puVar4[1],puVar4[2]);
  local_30 = *piVar3;
  local_2c = piVar3[1];
  local_28 = piVar3[2];
  piVar3 = (int *)FUN_00586310(local_c,iVar7,iVar5,iVar6);
  local_3c = *piVar3;
  local_38 = piVar3[1];
  local_34 = piVar3[2];
  piVar1[0x81] = local_3c;
  piVar1[0x4b] = local_3c;
  piVar1[0x85] = local_38;
  piVar1[0x4f] = local_38;
  piVar1[0x7e] = param_2;
  piVar1[0x89] = local_34;
  piVar1[0x53] = local_34;
  piVar1[0x7f] = param_3;
  piVar1[0x82] = local_30;
  piVar1[0x80] = param_4;
  piVar1[0x4c] = local_30;
  piVar1[0x86] = local_2c;
  piVar1[0x50] = local_2c;
  piVar1[0x8a] = local_28;
  piVar1[0x54] = local_28;
  piVar1[0x83] = local_24;
  piVar1[0x4d] = local_24;
  piVar1[0x87] = local_20;
  piVar1[0x51] = local_20;
  piVar1[0x8b] = local_1c;
  piVar1[0x55] = local_1c;
  if (piVar1[0x4a] != 0) {
    FUN_0052b490(piVar1);
  }
  return 0;
}

