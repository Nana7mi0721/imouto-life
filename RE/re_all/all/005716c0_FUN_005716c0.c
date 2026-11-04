
uint FUN_005716c0(int *param_1,int param_2,uint param_3)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  longlong lVar9;
  uint local_20;
  int local_14;
  int local_c;
  
  if ((param_1[8] == 1) && (param_1[9] != 0)) {
    iVar4 = FUN_00571330(param_1);
    while (iVar4 == 0) {
      FUN_0056da20(1);
      iVar4 = FUN_00571330(param_1);
    }
  }
  piVar2 = (int *)*param_1;
  iVar4 = param_1[1];
  if (*piVar2 == 0) {
    local_14 = *(int *)(iVar4 + 0x34);
    uVar5 = *(uint *)(iVar4 + 0x30);
    uVar8 = *(uint *)(iVar4 + 0x28);
    local_c = *(int *)(iVar4 + 0x2c);
    local_20 = piVar2[4];
    iVar4 = piVar2[5];
  }
  else {
    uVar5 = *(uint *)(iVar4 + 0x24);
    uVar8 = *(uint *)(iVar4 + 0x20);
    local_20 = piVar2[4];
    iVar4 = 0;
    local_14 = 0;
    local_c = 0;
  }
  if (param_1[5] != 1) {
    uVar3 = param_1[6];
    iVar7 = param_1[7];
    if ((uVar5 != uVar3) || (local_14 != iVar7)) {
      if ((local_14 - iVar7 == (uint)(uVar5 < uVar3)) && (uVar5 - uVar3 <= param_3)) {
        param_3 = uVar5 - uVar3;
      }
      if (param_1[2] == 0) {
        if (*(int *)(*param_1 + 0x864) == 1) {
          FUN_0056d420(param_2,*(int *)(*param_1 + 0x40) + uVar3 + uVar8 + local_20,param_3);
          piVar2 = (int *)*param_1;
          if (piVar2[0x21f] != 0) {
            if (*piVar2 == 0) {
              FUN_0056e590(param_3,0,param_1[6] + uVar5,
                           param_1[7] + local_14 + (uint)CARRY4(param_1[6],uVar5),piVar2 + 0x216);
            }
            else if (*(ushort *)((int)piVar2 + 10) < 5) {
              uVar5 = param_1[6] + local_20;
              FUN_0056e590(param_3,0,uVar5 + uVar8,
                           param_1[7] + iVar4 + (uint)CARRY4(param_1[6],local_20) + local_c +
                           (uint)CARRY4(uVar5,uVar8),piVar2 + 0x216);
            }
            else {
              FUN_0056e590(param_3,0,param_1[6] + uVar5,
                           param_1[7] + local_14 + (uint)CARRY4(param_1[6],uVar5),piVar2 + 0x216);
            }
          }
        }
        else {
          iVar6 = uVar3 + local_20 + uVar8;
          iVar4 = iVar7 + iVar4 + (uint)CARRY4(uVar3,local_20) + local_c +
                  (uint)CARRY4(uVar3 + local_20,uVar8);
          param_1[10] = iVar6;
          param_1[0xb] = iVar4;
          lVar9 = FUN_0052dc10(param_1[4]);
          if (lVar9 != CONCAT44(iVar4,iVar6)) {
            FUN_0052dc20(param_1[4],iVar6,iVar4,0);
          }
          if (param_1[8] == 0) {
            piVar2 = (int *)*param_1;
            if (*piVar2 == 0) {
              iVar4 = param_1[6] + uVar5;
              iVar7 = param_1[7] + local_14 + (uint)CARRY4(param_1[6],uVar5);
            }
            else if (*(ushort *)((int)piVar2 + 10) < 5) {
              iVar7 = -1;
              iVar4 = -1;
            }
            else {
              iVar4 = param_1[6] + uVar5;
              iVar7 = param_1[7] + local_14 + (uint)CARRY4(param_1[6],uVar5);
            }
            FUN_0056e720(param_2,param_3,0,piVar2 + 0x216,iVar4,iVar7);
          }
          else {
            FUN_0052dcb0(param_2,param_3,1,param_1[4]);
            param_1[0xc] = param_2;
            param_1[0xe] = param_3;
            param_1[0xf] = (int)param_3 >> 0x1f;
            param_1[9] = 2;
          }
        }
      }
      else {
        FUN_0056d420(param_2,uVar3 + param_1[2],param_3);
      }
      puVar1 = (uint *)(param_1 + 6);
      uVar5 = *puVar1;
      *puVar1 = *puVar1 + param_3;
      param_1[5] = 0;
      param_1[7] = param_1[7] + ((int)param_3 >> 0x1f) + (uint)CARRY4(uVar5,param_3);
      return param_3;
    }
    param_1[5] = 1;
  }
  return 0;
}

