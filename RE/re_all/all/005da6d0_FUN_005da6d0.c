
/* WARNING: Removing unreachable block (ram,0x005da93c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005da6d0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int unaff_EBX;
  uint unaff_EBP;
  ushort in_FPUControlWord;
  undefined8 uVar9;
  undefined8 uVar10;
  longlong lVar11;
  uint *puVar12;
  undefined8 *puVar13;
  undefined1 *puVar14;
  undefined4 uVar15;
  undefined8 local_4f8;
  undefined8 local_4f0;
  uint local_4e8;
  int local_4e4;
  int local_4dc;
  ushort local_4d8;
  undefined4 uStack_4d4;
  undefined4 uStack_4d0;
  undefined4 uStack_4cc;
  undefined4 uStack_4c8;
  double local_4c4;
  undefined1 local_4bc [16];
  undefined1 auStack_4ac [12];
  undefined4 uStack_4a0;
  undefined4 uStack_49c;
  undefined1 uStack_440;
  undefined1 uStack_43f;
  undefined1 uStack_43e;
  undefined1 uStack_43c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (*(int *)(param_1 + 0x56c) == 0) goto LAB_005da9f1;
  if (*(int *)(param_1 + 0xcc) == 0) {
    uVar9 = FUN_00550090(0);
    iVar6 = (int)((ulonglong)uVar9 >> 0x20);
    uVar8 = (uint)uVar9;
    local_4f8 = uVar9;
    if ((*(double *)(param_1 + 0x5f0) < _DAT_007d81e0) ||
       (_DAT_007d81d8 < *(double *)(param_1 + 0x5f0))) {
      local_4e8 = uVar8 - *(uint *)(param_1 + 0x5c8);
      local_4c4 = *(double *)(param_1 + 0x5f0) * _DAT_007d5fe0;
      local_4e4 = (iVar6 - *(int *)(param_1 + 0x5cc)) - (uint)(uVar8 < *(uint *)(param_1 + 0x5c8));
      local_4d8 = in_FPUControlWord | 0xc00;
      local_4f0._0_4_ = (int)ROUND(local_4c4);
      local_4f0._4_4_ = (int)local_4f0 >> 0x1f;
      puVar14 = local_4bc;
      puVar13 = &local_4f0;
      puVar12 = &local_4e8;
      local_4dc = (int)local_4f0;
      FUN_0056d6c0();
      local_4f0._0_4_ = 0x10000;
      local_4f0._4_4_ = 0;
      FUN_0056d730(local_4bc,&local_4f0,&local_4e8,puVar12,puVar13,puVar14);
      puVar12 = (uint *)(param_1 + 0x5d0);
      uVar8 = *puVar12;
      *puVar12 = *puVar12 + local_4e8;
      *(int *)(param_1 + 0x5d4) =
           *(int *)(param_1 + 0x5d4) + local_4e4 + (uint)CARRY4(uVar8,local_4e8);
    }
    else {
      uVar5 = uVar8 - *(uint *)(param_1 + 0x5c8);
      puVar12 = (uint *)(param_1 + 0x5d0);
      uVar3 = *puVar12;
      *puVar12 = *puVar12 + uVar5;
      *(int *)(param_1 + 0x5d4) =
           *(int *)(param_1 + 0x5d4) +
           ((iVar6 - *(int *)(param_1 + 0x5cc)) - (uint)(uVar8 < *(uint *)(param_1 + 0x5c8))) +
           (uint)CARRY4(uVar3,uVar5);
    }
    local_4e8 = *(uint *)(param_1 + 0x5d0);
    local_4e4 = *(undefined4 *)(param_1 + 0x5d4);
    *(undefined8 *)(param_1 + 0x5c8) = uVar9;
    local_4f0 = __alldiv((ulonglong)*(uint *)(param_1 + 0x580) * 0x10000,
                         *(undefined4 *)(param_1 + 0x584),0);
    puVar14 = local_4bc;
    puVar13 = &local_4f0;
    puVar12 = &local_4e8;
    FUN_0056d6c0();
    local_4f0._0_4_ = 0x42400000;
    local_4f0._4_4_ = 0xf;
    FUN_0056d730(local_4bc,&local_4f0,&local_4e8,puVar12,puVar13,puVar14);
    iVar6 = *(int *)(param_1 + 0x5b8);
    uVar8 = local_4e8;
    if (iVar6 <= (int)local_4e8) {
      if ((*(byte *)(param_1 + 0x30) & 2) == 0) {
        uVar8 = iVar6 - 1;
      }
      else {
        uVar8 = (int)local_4e8 % iVar6;
      }
    }
    uVar3 = *(uint *)(param_1 + 0x5c0);
    if (uVar8 == uVar3) {
      if ((iVar6 + -1 <= (int)uVar8) && ((*(byte *)(param_1 + 0x30) & 2) == 0)) {
        if (*(int *)(param_1 + 0x5e0) != -1) {
          iVar6 = FUN_00560f10(*(int *)(param_1 + 0x5e0));
          if (iVar6 == 1) goto LAB_005da9d0;
        }
        *(undefined4 *)(param_1 + 200) = 0;
        *(undefined4 *)(param_1 + 0xcc) = 1;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x520) = 1;
      if ((int)uVar8 < (int)uVar3) {
        FUN_005da550(param_1,uVar8);
        if (*(int *)(param_1 + 0x5d8) == 0) {
          FUN_00561a00();
          *(undefined8 *)(param_1 + 0xa0) = uVar9;
          goto LAB_005da9d0;
        }
      }
      else {
        local_4dc = uVar8 - uVar3;
        if (local_4dc == 2) {
          uVar9 = __alldiv(*(undefined4 *)(param_1 + 0x638),*(undefined4 *)(param_1 + 0x63c),10,0);
          uVar10 = __alldiv(uVar9,10,0);
          uVar8 = (uint)uVar10 + *(uint *)(param_1 + 0xa0);
          lVar11 = __alldiv(uVar8 - (uint)local_4f8,
                            (((int)((ulonglong)uVar10 >> 0x20) + *(int *)(param_1 + 0xa4) +
                             (uint)CARRY4((uint)uVar10,*(uint *)(param_1 + 0xa0))) - local_4f8._4_4_
                            ) - (uint)(uVar8 < (uint)local_4f8),uVar9);
          if (lVar11 < 2) {
            local_4dc = 1;
          }
          uVar9 = local_4f8;
        }
        FUN_005d9d70();
      }
      *(undefined8 *)(param_1 + 0xa0) = uVar9;
    }
  }
  else {
    if (DAT_00a37dc8 == 0) {
      iVar6 = *(int *)(param_1 + 0x618);
    }
    else {
      iVar6 = *(int *)(param_1 + 0x620);
    }
    if (iVar6 == 0) {
      FUN_005d9250();
    }
  }
LAB_005da9d0:
  if (*(code **)(param_1 + 0x560) != (code *)0x0) {
    (**(code **)(param_1 + 0x560))(param_1,*(undefined4 *)(param_1 + 0x564));
    *(undefined4 *)(param_1 + 0xd0) = 1;
  }
LAB_005da9f1:
  if (*(int *)(param_1 + 0x624) != 0) {
    if (*(int *)(*(int *)(param_1 + 0x634) + 0x188) != 0) {
      *(undefined4 *)(param_1 + 0x520) = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x634) + 0x188) = 0;
      if (*(int *)(param_1 + 0x560) != 0) {
        iVar6 = *(int *)(param_1 + 0x634);
        if ((*(int *)(iVar6 + 0x17c) != 0) &&
           ((*(int *)(iVar6 + 0x180) == 0 || (*(int *)(iVar6 + 0x16c) != 0)))) {
          *(undefined4 *)(param_1 + 0x504) = *(undefined4 *)(iVar6 + 400);
          *(undefined4 *)(param_1 + 0x508) = *(undefined4 *)(iVar6 + 0x194);
          *(undefined4 *)(param_1 + 0x50c) = *(undefined4 *)(iVar6 + 0x198);
          *(undefined4 *)(param_1 + 0x510) = *(undefined4 *)(iVar6 + 0x17c);
          *(undefined4 *)(param_1 + 0x51c) = 1;
          if (*(int *)(iVar6 + 0x178) == 0) {
            FUN_00544560(param_1 + 0xdc);
          }
          else if ((*(int *)(iVar6 + 0x178) == 1) && (*(int *)(param_1 + 0xc0) != 0)) {
            FUN_00544500(param_1 + 0xdc);
          }
          else {
            FUN_005444a0(param_1 + 0xdc);
          }
          *(int *)(param_1 + 0x524) = param_1 + 0xdc;
          (**(code **)(param_1 + 0x560))(param_1,*(undefined4 *)(param_1 + 0x564));
        }
        if (*(int *)(*(int *)(param_1 + 0x634) + 0x180) != 0) {
          puVar1 = (undefined4 *)(param_1 + 0x528);
          if (*(int *)(param_1 + 0x528) == -1) {
            FUN_005193b0(auStack_4ac);
            FUN_005194a0(auStack_4ac,0x20,0,0);
            uStack_4a0 = 1;
            uStack_49c = 8;
            uVar7 = FUN_005243b0(auStack_4ac,*(undefined4 *)(*(int *)(param_1 + 0x634) + 0x19c),
                                 *(undefined4 *)(*(int *)(param_1 + 0x634) + 0x1a0),0,0,0,0,0);
            *puVar1 = uVar7;
            FUN_00580830(uVar7,puVar1);
          }
          puVar2 = (undefined4 *)(param_1 + 0x52c);
          if (*(int *)(param_1 + 0x52c) == -1) {
            FUN_005193b0(auStack_4ac);
            FUN_005194a0(auStack_4ac,0x20,0,0);
            uStack_4a0 = 2;
            uStack_49c = 8;
            uVar7 = FUN_005243b0(auStack_4ac,*(undefined4 *)(*(int *)(param_1 + 0x634) + 0x1a8),
                                 *(undefined4 *)(*(int *)(param_1 + 0x634) + 0x1ac),0,0,0,0,0);
            *puVar2 = uVar7;
            FUN_00580830(uVar7,puVar2);
          }
          uVar15 = 0x440;
          puVar14 = &uStack_440;
          uVar7 = 0;
          FUN_0056d380();
          iVar6 = *(int *)(param_1 + 0x634);
          uStack_4cc = *(undefined4 *)(iVar6 + 0x19c);
          uStack_4c8 = *(undefined4 *)(iVar6 + 0x1a0);
          uStack_10 = *(undefined4 *)(iVar6 + 0x1a4);
          uStack_c = *(undefined4 *)(iVar6 + 0x180);
          uStack_440 = 0;
          uStack_43c = 1;
          uStack_43f = 1;
          uStack_43e = 8;
          uStack_4d4 = 0;
          uStack_4d0 = 0;
          uStack_18 = uStack_4cc;
          uStack_14 = uStack_4c8;
          FUN_00518620(&uStack_4d4,0,0,*puVar1,&uStack_440,0,0,0,0,0,puVar14,uVar7,uVar15);
          iVar6 = *(int *)(param_1 + 0x634);
          uStack_4cc = *(undefined4 *)(iVar6 + 0x1a8);
          uStack_4c8 = *(undefined4 *)(iVar6 + 0x1ac);
          uStack_10 = *(undefined4 *)(iVar6 + 0x1b0);
          uStack_c = *(undefined4 *)(iVar6 + 0x184);
          uStack_440 = 0;
          uStack_43c = 2;
          uStack_43f = 2;
          uStack_43e = 8;
          uStack_4d4 = 0;
          uStack_4d0 = 0;
          uStack_18 = uStack_4cc;
          uStack_14 = uStack_4c8;
          FUN_00518620(&uStack_4d4,0,0,*puVar2,&uStack_440,0,0,0,0,0);
          (**(code **)(param_1 + 0x560))(param_1,*(undefined4 *)(param_1 + 0x564));
        }
      }
    }
    piVar4 = *(int **)(param_1 + 0x62c);
    if ((piVar4 != (int *)0x0) && (*(int *)(param_1 + 0x628) != 0)) {
      (**(code **)(*piVar4 + 0x30))(piVar4,&local_4f8);
      if ((*(int *)(param_1 + 0xac) <= unaff_EBX) &&
         ((*(int *)(param_1 + 0xac) < unaff_EBX || (*(uint *)(param_1 + 0xa8) <= unaff_EBP)))) {
        if ((*(byte *)(param_1 + 0x30) & 2) != 0) {
          uStack_4cc = 0;
          uStack_4c8 = 0;
          (**(code **)(**(int **)(param_1 + 0x62c) + 0x38))
                    (*(int **)(param_1 + 0x62c),local_4bc + -0x44,1,&uStack_4cc,0);
          (**(code **)(**(int **)(param_1 + 0x628) + 0x1c))(*(int **)(param_1 + 0x628));
          return 0;
        }
        (**(code **)(**(int **)(param_1 + 0x628) + 0x20))();
        *(undefined4 *)(param_1 + 200) = 0;
        *(undefined4 *)(param_1 + 0xcc) = 1;
      }
    }
  }
  return 0;
}

