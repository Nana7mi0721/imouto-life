
uint FUN_0052e4f0(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined8 uVar14;
  int iStack_a4;
  int iStack_a0;
  undefined8 uStack_9c;
  undefined4 uStack_94;
  undefined8 uStack_90;
  int iStack_88;
  int iStack_84;
  undefined1 auStack_80 [64];
  undefined1 auStack_40 [64];
  
  uVar13 = 0;
  if ((((((DAT_00cc76d0 == 0) || ((int)param_3 < 0)) || ((param_3 & 0x7c000000) != DAT_00cc76f8)) ||
       ((DAT_00cc7700 <= (int)(param_3 & 0xffff) ||
        (piVar1 = *(int **)(DAT_00cc76d4 + (param_3 & 0xffff) * 4), piVar1 == (int *)0x0)))) ||
      ((*piVar1 * 0x10000 != (param_3 & 0x3ff0000) ||
       ((piVar1[4] != 0 || (iVar4 = (*(code *)piVar1[0x10])(piVar1[0x13]), iVar4 != 0)))))) ||
     (iVar4 = FUN_0052ce00(), iVar4 < 0)) {
    return 0xffffffff;
  }
  if (DAT_00aba24c == 0) {
    FUN_0057a980();
  }
  iVar5 = thunk_FUN_00572ac0(DAT_00aba24c);
  iVar4 = piVar1[0x14];
  if ((piVar1[0x14] == 0) && (iVar4 = DAT_00aba24c, DAT_00aba24c == 0)) {
    FUN_0057a980();
    iVar4 = DAT_00aba24c;
  }
  uStack_94 = thunk_FUN_00572ac0(iVar4);
  iVar4 = piVar1[0x14];
  if ((piVar1[0x14] == 0) && (iVar4 = DAT_00aba24c, DAT_00aba24c == 0)) {
    FUN_0057a980();
    iVar4 = DAT_00aba24c;
  }
  uVar2 = CONCAT44(uStack_90._4_4_,(undefined4)uStack_90);
  uVar14 = CONCAT44(uStack_9c._4_4_,(undefined4)uStack_9c);
  uVar6 = param_2 - 1;
  iVar11 = (int)uVar6 >> 0x1f;
  iStack_a4 = 0;
  uStack_9c = CONCAT44(uStack_9c._4_4_,(undefined4)uStack_9c);
  uStack_90 = CONCAT44(uStack_90._4_4_,(undefined4)uStack_90);
  if ((iVar11 < 0) ||
     ((uVar10 = uVar13, uStack_9c = uVar14, uStack_90 = uVar2, -1 < (int)uVar6 && (uVar6 == 0)))) {
LAB_0052e8e8:
    if (DAT_00aba24c == 0) {
      FUN_0057a980();
    }
    thunk_FUN_00573310(0,DAT_00aba24c,uVar13 * iVar5 + param_1,(param_2 - uVar13) * iVar5);
    return uVar13;
  }
  do {
    uVar14 = (*(code *)piVar1[0xd])(piVar1[0x13]);
    uStack_9c = uVar14;
    iVar7 = FUN_0052cf20(&iStack_84,&iStack_a0,iVar4);
    iVar9 = iStack_84;
    uVar13 = uVar10;
    if ((iVar7 == 0) || (iStack_84 == 0)) goto LAB_0052e8e8;
    if (DAT_00aba24c == 0) {
      FUN_0057a980();
    }
    iVar7 = DAT_00aba24c;
    if (DAT_00aba24c == 0) {
      FUN_0057a980();
    }
    uVar8 = thunk_FUN_005736c0(iVar9,iVar4,DAT_00aba24c,iVar7,auStack_80,0x40);
    iVar7 = thunk_FUN_00573310(uVar8);
    if (iVar9 == 0xd) {
      uVar14 = (*(code *)piVar1[0xd])(piVar1[0x13]);
      uStack_90 = uVar14;
      iVar9 = FUN_0052cf20(&iStack_88,&iStack_a0,iVar4);
      if (iVar9 == 0) {
        uVar12 = iVar7 / iVar5;
        iVar4 = ((int)uVar12 >> 0x1f) + iStack_a4 + (uint)CARRY4(uVar12,uVar10);
        if ((iVar4 < iVar11) || ((iVar4 <= iVar11 && (uVar12 + uVar10 <= uVar6)))) {
          FUN_0056d420(uVar10 * iVar5 + param_1,auStack_80,iVar7);
          uVar13 = uVar12 + uVar10;
        }
        else {
          (*(code *)piVar1[0xe])(piVar1[0x13],uStack_9c,0);
        }
        goto LAB_0052e8e8;
      }
      if (DAT_00aba24c == 0) {
        FUN_0057a980();
      }
      iVar9 = DAT_00aba24c;
      if (DAT_00aba24c == 0) {
        FUN_0057a980();
      }
      iVar3 = iStack_88;
      uVar8 = thunk_FUN_005736c0(iStack_88,iVar4,DAT_00aba24c,iVar9,auStack_40,0x40);
      iStack_a0 = thunk_FUN_00573310(uVar8);
      if (iVar3 == 10) goto LAB_0052e8e8;
      uVar13 = iVar7 / iVar5;
      uVar12 = uVar13 + uVar10;
      iVar9 = ((int)uVar13 >> 0x1f) + iStack_a4 + (uint)CARRY4(uVar13,uVar10);
      if ((iVar11 < iVar9) || ((iVar11 <= iVar9 && (uVar6 < uVar12)))) goto LAB_0052e8d6;
      FUN_0056d420(uVar10 * iVar5 + param_1,auStack_80,iVar7);
      uVar10 = iStack_a0 / iVar5;
      uVar13 = uVar10 + uVar12;
      iStack_a4 = ((int)uVar10 >> 0x1f) + iVar9 + (uint)CARRY4(uVar10,uVar12);
      if ((iVar11 < iStack_a4) || ((iVar11 <= iStack_a4 && (uVar6 < uVar13)))) {
        (*(code *)piVar1[0xe])(piVar1[0x13],uStack_90,0);
        uVar13 = uVar12;
        goto LAB_0052e8e8;
      }
      FUN_0056d420(uVar12 * iVar5 + param_1,auStack_40,iStack_a0);
    }
    else {
      uVar12 = iVar7 / iVar5;
      uVar13 = uVar12 + uVar10;
      iStack_a4 = ((int)uVar12 >> 0x1f) + iStack_a4 + (uint)CARRY4(uVar12,uVar10);
      if ((iVar11 < iStack_a4) || ((iVar11 <= iStack_a4 && (uVar6 < uVar13)))) {
LAB_0052e8d6:
        (*(code *)piVar1[0xe])(piVar1[0x13],uStack_9c,0);
        uVar13 = uVar10;
        goto LAB_0052e8e8;
      }
      FUN_0056d420(uVar10 * iVar5 + param_1,auStack_80,iVar7);
    }
    uVar10 = uVar13;
    if ((iVar11 <= iStack_a4) && ((iVar11 < iStack_a4 || (uVar6 <= uVar13)))) goto LAB_0052e8e8;
  } while( true );
}

