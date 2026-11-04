
int FUN_006b9780(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  sbyte sVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  longlong lVar12;
  int local_50;
  sbyte local_4c;
  int *local_48;
  int local_44;
  int local_40;
  undefined1 local_30 [48];
  
  iVar2 = param_1;
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    return -1;
  }
  if (param_2[1] == 0) {
    *(undefined1 *)(param_1 + 0x368) = 1;
    *(undefined4 *)(param_1 + 0xe8) = 0;
  }
  else {
    FUN_006bf010(param_1 + 0xc9b4,*param_2,param_2[1]);
    iVar4 = FUN_006b9ca0(param_1);
    if (iVar4 < 0) {
      return iVar4;
    }
    if (*(char *)(param_1 + 0x368) == '\0') {
      FUN_006b9d60();
    }
    else {
      FUN_006b9e90(param_1);
    }
  }
  if ((*(char *)(param_1 + 0x368) != '\0') &&
     ((*(int *)(param_1 + 0x20c) < 0 || (*(int *)(param_1 + 0x210) < 0)))) {
    FUN_006bc4b0(param_1);
  }
  if (*(int *)(param_1 + 0xe8) < 1) {
    uVar1 = *(undefined4 *)(param_1 + 0x350);
    uVar7 = *(uint *)(param_1 + 0x358);
    iVar2 = *(int *)(param_1 + 0x35c);
    lVar3 = *(longlong *)(param_1 + 0x358);
    lVar12 = __allshl();
    lVar3 = (lVar12 - CONCAT44(*(undefined4 *)(param_1 + 0x354),uVar1)) + lVar3;
    *(int *)(param_1 + 0x360) = (int)lVar3;
    *(uint *)(param_1 + 0x358) = uVar7 + 1;
    *(int *)(param_1 + 0x364) = (int)((ulonglong)lVar3 >> 0x20);
    *(uint *)(param_1 + 0x35c) = iVar2 + (uint)(0xfffffffe < uVar7);
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(param_1 + 0x360);
      param_3[1] = *(undefined4 *)(param_1 + 0x364);
    }
    return 1;
  }
  for (iVar4 = 0; (iVar4 == *(int *)(param_1 + 0x20c) || (iVar4 == *(int *)(param_1 + 0x210)));
      iVar4 = iVar4 + 1) {
  }
  *(int *)(param_1 + 0x214) = iVar4;
  iVar11 = iVar4 * 0x30 + param_1;
  *(undefined4 *)(param_1 + 0x22c) = *(undefined4 *)(iVar11 + 0xf8);
  if (*(char *)(param_1 + 0x368) == '\0') {
    *(undefined4 *)(param_1 + 0x350) = *(undefined4 *)(param_1 + 0x358);
    *(undefined4 *)(param_1 + 0x354) = *(undefined4 *)(param_1 + 0x35c);
  }
  else {
    FUN_006ba2e0(param_1);
    FUN_006ba390(param_1);
  }
  FUN_006ba690(param_1);
  FUN_006ba8a0(param_1);
  uVar1 = *(undefined4 *)(param_1 + 0x350);
  uVar7 = *(uint *)(param_1 + 0x358);
  iVar9 = *(int *)(param_1 + 0x35c);
  lVar3 = *(longlong *)(param_1 + 0x358);
  lVar12 = __allshl();
  lVar3 = (lVar12 - CONCAT44(*(undefined4 *)(param_1 + 0x354),uVar1)) + lVar3;
  *(int *)(param_1 + 0x360) = (int)lVar3;
  *(uint *)(param_1 + 0x358) = uVar7 + 1;
  *(int *)(param_1 + 0x364) = (int)((ulonglong)lVar3 >> 0x20);
  *(uint *)(param_1 + 0x35c) = iVar9 + (uint)(0xfffffffe < uVar7);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + 0x360);
    param_3[1] = *(undefined4 *)(param_1 + 0x364);
  }
  FUN_006baeb0(param_1,param_1 + 0xd360);
  FUN_006b8e40(local_30,param_1 + 0xd328);
  param_1 = 0;
  local_50 = 0;
  do {
    local_44 = *(int *)(iVar2 + 0x4c);
    local_48 = (int *)(iVar2 + 0x4c);
    uVar7 = (uint)(*(int *)(iVar2 + 0xdf20) + local_50 < local_44);
    iVar9 = 0;
    piVar10 = (int *)(iVar2 + 0xdee4);
    local_40 = local_44;
    do {
      if ((iVar9 == 0) || ((*(byte *)(iVar2 + 0x30) & 2) != 0)) {
        local_4c = 0;
        sVar6 = 0;
      }
      else {
        sVar6 = 1;
        local_4c = 1;
      }
      piVar10[-3] = local_50 >> sVar6;
      iVar8 = *local_48;
      iVar5 = (local_50 >> sVar6) + (*(int *)(iVar2 + 0xdf20) >> sVar6);
      *piVar10 = (-(uint)(iVar5 < iVar8) & iVar5 - iVar8) + iVar8;
      FUN_006b8f30(iVar2,iVar2 + 0xd360,iVar9);
      FUN_006bb360(iVar2,iVar2 + 0xd360,iVar9);
      param_3 = (undefined4 *)0x0;
      iVar8 = 0;
      if (*(int *)(iVar2 + 0xdf24) != 0) {
        FUN_006bdb40(iVar2,iVar2 + 0xd460,2,iVar9,piVar10[-3] - param_1,*piVar10 - uVar7);
        iVar8 = param_1;
        param_3 = (undefined4 *)uVar7;
      }
      FUN_006bd730(iVar2,iVar4,iVar9,piVar10[-3] * 8 + iVar8 * -10,*piVar10 * 8 + (int)param_3 * -10
                  );
      if (*(int *)(iVar2 + 0xdf28) < (int)((uint)(iVar9 != 0) * 3 + 2)) {
        if (*(int *)(iVar2 + 0xdf24) != 0) {
          iVar8 = iVar8 + param_1;
          param_3 = (undefined4 *)((int)param_3 + uVar7);
        }
      }
      else {
        param_3 = (undefined4 *)((int)param_3 + uVar7);
        iVar8 = iVar8 + param_1;
        FUN_006bb600(iVar2,iVar2 + 0xd328,iVar11 + 0xec,iVar9,piVar10[-3] - iVar8,
                     *piVar10 - (int)param_3);
        if ((int)((uint)(iVar9 != 0) * 3 + 3) <= *(int *)(iVar2 + 0xdf28)) {
          iVar8 = iVar8 + param_1;
          param_3 = (undefined4 *)((int)param_3 + uVar7);
          FUN_006bbd40(iVar2,iVar2 + 0xd328,iVar9,piVar10[-3] - iVar8,*piVar10 - (int)param_3);
        }
      }
      iVar8 = piVar10[-3] - iVar8 << local_4c;
      local_44 = local_44 + (-(uint)(iVar8 < local_44) & iVar8 - local_44);
      iVar8 = *piVar10 - (int)param_3 << local_4c;
      piVar10 = piVar10 + 1;
      local_40 = local_40 + (-(uint)(iVar8 < local_40) & iVar8 - local_40);
      iVar9 = iVar9 + 1;
      local_48 = local_48 + 8;
    } while (iVar9 < 3);
    if (*(code **)(iVar2 + 0xd35c) != (code *)0x0) {
      (**(code **)(iVar2 + 0xd35c))
                (*(undefined4 *)(iVar2 + 0xd358),local_30,*(int *)(iVar2 + 0x4c) - local_40,
                 *(int *)(iVar2 + 0x4c) - local_44);
    }
    local_50 = local_50 + *(int *)(iVar2 + 0xdf20);
    param_1 = 1;
  } while (uVar7 != 0);
  iVar11 = 0;
  do {
    FUN_006bd820(iVar2,iVar4,iVar11);
    iVar11 = iVar11 + 1;
  } while (iVar11 < 3);
  if (*(char *)(iVar2 + 0x368) == '\0') {
    *(undefined4 *)(iVar2 + 0x210) = *(undefined4 *)(iVar2 + 0x214);
    *(undefined4 *)(iVar2 + 0x20c) = *(undefined4 *)(iVar2 + 0x214);
    *(undefined4 *)(iVar2 + 0x228) = *(undefined4 *)(iVar2 + 0x22c);
    *(undefined4 *)(iVar2 + 0x224) = *(undefined4 *)(iVar2 + 0x22c);
    return 0;
  }
  *(undefined4 *)(iVar2 + 0x210) = *(undefined4 *)(iVar2 + 0x214);
  *(undefined4 *)(iVar2 + 0x228) = *(undefined4 *)(iVar2 + 0x22c);
  return 0;
}

