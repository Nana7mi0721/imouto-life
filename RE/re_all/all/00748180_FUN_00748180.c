
void FUN_00748180(undefined4 param_1,int param_2,int *param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40 [9];
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar4 = param_3;
  piVar6 = local_40;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar6 = *piVar4;
    piVar4 = piVar4 + 1;
    piVar6 = piVar6 + 1;
  }
  uVar2 = (uint)(local_40[1] < local_40[3]);
  uVar3 = (uint)(local_40[3] < local_40[1]);
  uVar7 = (uint)(local_40[0] < local_40[2]);
  uVar5 = (uint)(local_40[2] < local_40[0]);
  if (local_40[uVar2 * 2 + 1] < local_40[5]) {
    uVar2 = 2;
  }
  if (local_40[5] < local_40[uVar3 * 2 + 1]) {
    uVar3 = 2;
  }
  if (local_40[uVar7 * 2] < local_40[4]) {
    uVar7 = 2;
  }
  if (local_40[4] < local_40[uVar5 * 2]) {
    uVar5 = 2;
  }
  if (local_40[uVar2 * 2 + 1] < local_40[7]) {
    uVar2 = 3;
  }
  if (local_40[7] < local_40[uVar3 * 2 + 1]) {
    uVar3 = 3;
  }
  if (local_40[uVar7 * 2] < local_40[6]) {
    uVar7 = 3;
  }
  if (local_40[6] < local_40[uVar5 * 2]) {
    uVar5 = 3;
  }
  local_50 = local_40[uVar5 * 2] + -2;
  local_4c = local_40[uVar3 * 2 + 1] + -2;
  local_48 = local_40[uVar7 * 2] + 4;
  local_44 = local_40[uVar2 * 2 + 1] + 4;
  FUN_00514e10(&local_50,&DAT_00dca3e4);
  if ((local_50 != local_48) && (local_4c != local_44)) {
    local_10 = param_3[6];
    local_40[0] = *param_3;
    local_40[4] = param_3[2];
    local_40[1] = param_3[1];
    local_40[8] = param_3[4];
    local_c = param_3[7];
    local_40[5] = param_3[3];
    local_1c = param_3[5];
    local_40[2] = 0;
    local_40[3] = 0;
    local_40[7] = 0;
    local_18 = 0;
    local_40[6] = *(undefined4 *)(param_2 + 4);
    local_14 = *(undefined4 *)(param_2 + 8);
    local_8 = local_40[6];
    local_4 = local_14;
    FUN_00707fe0(param_1,param_2,local_40,param_4,param_5,0);
    FUN_00707fe0(param_1,param_2,local_40 + 4,param_4,param_5,0);
  }
  return;
}

