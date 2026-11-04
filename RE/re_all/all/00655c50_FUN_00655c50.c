
/* WARNING: Removing unreachable block (ram,0x00655e02) */

undefined4 FUN_00655c50(int param_1,int param_2,ushort param_3)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  
  FUN_0065f680(param_1);
  if (*(int *)(param_1 + 0xb0) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0xb0));
  }
  iVar4 = FUN_00650c00(param_1,*(undefined4 *)(param_1 + 0xa8),8,
                       s_for__StripByteCounts__array_00a0a2bc);
  *(int *)(param_1 + 0xb0) = iVar4;
  if (iVar4 == 0) {
    return 0xffffffff;
  }
  if (*(short *)(param_1 + 0x58) == 1) {
    if ((*(uint *)(param_1 + 0xc) & 0x400) == 0) {
      uVar9 = FUN_00652ae0(param_1);
      uVar5 = 0;
      if (*(int *)(param_1 + 0xa8) != 0) {
        uVar9 = __allmul(*(uint *)(param_1 + 0x3c) / *(uint *)(param_1 + 0xa4),0,uVar9);
        do {
          iVar4 = *(int *)(param_1 + 0xb0);
          uVar5 = uVar5 + 1;
          *(int *)(iVar4 + -8 + uVar5 * 8) = (int)uVar9;
          *(int *)(iVar4 + -4 + uVar5 * 8) = (int)((ulonglong)uVar9 >> 0x20);
        } while (uVar5 < *(uint *)(param_1 + 0xa8));
      }
    }
    else {
      uVar9 = FUN_00651850();
      uVar5 = 0;
      if (*(int *)(param_1 + 0xa8) != 0) {
        do {
          iVar4 = *(int *)(param_1 + 0xb0);
          uVar5 = uVar5 + 1;
          *(int *)(iVar4 + -8 + uVar5 * 8) = (int)uVar9;
          *(int *)(iVar4 + -4 + uVar5 * 8) = (int)((ulonglong)uVar9 >> 0x20);
        } while (uVar5 < *(uint *)(param_1 + 0xa8));
      }
    }
  }
  else {
    uVar7 = (**(code **)(param_1 + 0x288))(*(undefined4 *)(param_1 + 0x274));
    if ((*(uint *)(param_1 + 0xc) & 0x80000) == 0) {
      uVar5 = (uint)param_3 * 0xc + 0xe;
    }
    else {
      uVar5 = (uint)param_3 * 0x14 + 0x20;
    }
    uVar3 = (ulonglong)uVar5;
    for (; param_3 != 0; param_3 = param_3 - 1) {
      FUN_00653680(*(undefined2 *)(param_2 + 2));
      iVar4 = FUN_00653680(*(undefined2 *)(param_2 + 2));
      if (iVar4 == 0) {
        FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"EstimateStripByteCounts",
                     s_Cannot_determine_size_of_unknown_00a0a28c,*(undefined2 *)(param_2 + 2));
        return 0xffffffff;
      }
      lVar8 = __allmul(*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc),iVar4,0);
      iVar4 = (int)((ulonglong)lVar8 >> 0x20);
      if ((*(uint *)(param_1 + 0xc) & 0x80000) == 0) {
        if ((iVar4 == 0) && ((uint)lVar8 < 5)) {
LAB_00655d5d:
          lVar8 = 0;
        }
      }
      else if ((iVar4 == 0) && ((uint)lVar8 < 9)) goto LAB_00655d5d;
      uVar3 = lVar8 + uVar3;
      param_2 = param_2 + 0x18;
    }
    lVar8 = uVar7 - uVar3;
    if (*(short *)(param_1 + 0x7e) == 2) {
      lVar8 = __aulldiv(lVar8,*(undefined2 *)(param_1 + 0x62),0);
    }
    uVar5 = 0;
    if (*(int *)(param_1 + 0xa8) != 0) {
      do {
        iVar4 = *(int *)(param_1 + 0xb0);
        uVar5 = uVar5 + 1;
        *(int *)(iVar4 + -8 + uVar5 * 8) = (int)lVar8;
        *(int *)(iVar4 + -4 + uVar5 * 8) = (int)((ulonglong)lVar8 >> 0x20);
      } while (uVar5 < *(uint *)(param_1 + 0xa8));
    }
    iVar6 = uVar5 - 1;
    uVar5 = *(uint *)(*(int *)(param_1 + 0xac) + iVar6 * 8);
    puVar1 = (uint *)(*(int *)(param_1 + 0xb0) + iVar6 * 8);
    iVar4 = *(int *)(*(int *)(param_1 + 0xac) + 4 + iVar6 * 8);
    uVar2 = *puVar1;
    if (uVar7 < CONCAT44(iVar4 + *(int *)(*(int *)(param_1 + 0xb0) + 4 + iVar6 * 8) +
                         (uint)CARRY4(uVar5,uVar2),uVar5 + uVar2)) {
      *(ulonglong *)puVar1 = uVar7 - CONCAT44(iVar4,uVar5);
    }
  }
  uVar5 = *(uint *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x28) = uVar5 | 0x1000000;
  if ((uVar5 & 0x20000) == 0) {
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x3c);
  }
  return 1;
}

