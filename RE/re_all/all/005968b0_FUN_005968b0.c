
/* WARNING: Removing unreachable block (ram,0x00596bfb) */

undefined4 FUN_005968b0(void)

{
  int *piVar1;
  undefined2 *puVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  short *psVar8;
  int unaff_ESI;
  undefined8 uVar9;
  longlong lVar10;
  undefined1 auStack_20 [4];
  undefined1 uStack_1c;
  int local_18;
  uint uStack_14;
  undefined8 uStack_10;
  undefined4 uStack_8;
  
  piVar1 = (int *)(unaff_ESI + 0x4a);
  psVar8 = (short *)0x0;
  *piVar1 = 0;
  *(undefined4 *)(unaff_ESI + 0x56) = 0xffffffff;
  *(undefined4 *)(unaff_ESI + 0x5a) = 0xffffffff;
  (**(code **)(unaff_ESI + 0x14))(&local_18,8,1,*(undefined4 *)(unaff_ESI + 0x24));
  if (local_18 == 0x46464952) {
    uStack_1c = 0;
    (**(code **)(unaff_ESI + 0x14))(auStack_20,4,1,*(undefined4 *)(unaff_ESI + 0x24));
    iVar5 = FUN_0056d100(auStack_20,&DAT_007d6160);
    if (iVar5 == 0) {
      uStack_10 = (**(code **)(unaff_ESI + 0xc))(*(undefined4 *)(unaff_ESI + 0x24));
      iVar5 = (**(code **)(unaff_ESI + 0x18))(*(undefined4 *)(unaff_ESI + 0x24));
      while (iVar5 == 0) {
        (**(code **)(unaff_ESI + 0x14))(&local_18,8,1,*(undefined4 *)(unaff_ESI + 0x24));
        if (local_18 == 0x20746d66) break;
        (**(code **)(unaff_ESI + 0x10))
                  (*(undefined4 *)(unaff_ESI + 0x24),(uStack_14 & 1) + uStack_14,0,1);
        iVar5 = (**(code **)(unaff_ESI + 0x18))(*(undefined4 *)(unaff_ESI + 0x24));
      }
      iVar5 = (**(code **)(unaff_ESI + 0x18))(*(undefined4 *)(unaff_ESI + 0x24));
      if (iVar5 == 0) {
        psVar8 = (short *)FUN_0056e030(uStack_14,
                                       "..\\..\\..\\..\\Source\\Library\\Main\\DxSoundConvert.cpp",
                                       0x1ed);
        if (psVar8 != (short *)0x0) {
          uVar6 = (**(code **)(unaff_ESI + 0xc))(*(undefined4 *)(unaff_ESI + 0x24));
          *(undefined4 *)(unaff_ESI + 0x28) = uVar6;
          *(uint *)(unaff_ESI + 0x2c) = uStack_14;
          FUN_0056d380(piVar1,0,0x400);
          puVar2 = (undefined2 *)(unaff_ESI + 0x38);
          *(undefined4 *)(unaff_ESI + 0x56) = 0xffffffff;
          *(undefined4 *)(unaff_ESI + 0x5a) = 0xffffffff;
          FUN_0056d380(puVar2,0,0x12);
          (**(code **)(unaff_ESI + 0x14))(psVar8,uStack_14,1,*(undefined4 *)(unaff_ESI + 0x24));
          if (*psVar8 == 1) {
            uVar7 = uStack_14;
            if (0x12 < uStack_14) {
              uVar7 = 0x12;
            }
            FUN_0056d420(puVar2,psVar8,uVar7);
            if (uStack_14 != 0x10) goto LAB_00596a78;
            uVar3 = psVar8[6];
            uVar4 = psVar8[1];
            *(undefined2 *)(unaff_ESI + 0x48) = 0;
            *(short *)(unaff_ESI + 0x46) =
                 (short)((ulonglong)uVar3 / (ulonglong)(longlong)(int)(uint)uVar4) * 8;
LAB_00596a82:
            uVar7 = uStack_14;
          }
          else {
            if (*psVar8 != 3) goto LAB_00596ccd;
            iVar5 = *(int *)(psVar8 + 2);
            *(int *)(unaff_ESI + 0x3c) = iVar5;
            uVar3 = psVar8[1];
            *(ushort *)(unaff_ESI + 0x3a) = uVar3;
            uVar7 = (int)((uint)uVar3 * 0x10) >> 3;
            *(short *)(unaff_ESI + 0x44) = (short)uVar7;
            *(undefined2 *)(unaff_ESI + 0x46) = 0x10;
            *puVar2 = 1;
            *(uint *)(unaff_ESI + 0x40) = (uVar7 & 0xffff) * iVar5;
            *(int *)(unaff_ESI + 0x52) = iVar5;
            uVar6 = *(undefined4 *)(psVar8 + 4);
            *(undefined4 *)(unaff_ESI + 0x4e) = uVar6;
            iVar5 = FUN_0056e030(uVar6,"..\\..\\..\\..\\Source\\Library\\Main\\DxSoundConvert.cpp",
                                 0x214);
            *piVar1 = iVar5;
            if (iVar5 == 0) goto LAB_00596ce2;
LAB_00596a78:
            uVar7 = 0x12;
            if (uStack_14 < 0x13) goto LAB_00596a82;
          }
          FUN_0056d420(unaff_ESI + 0x5e,psVar8,uVar7);
          FUN_0056e1d0(psVar8);
          psVar8 = (short *)0x0;
          iVar5 = (**(code **)(unaff_ESI + 0x18))(*(undefined4 *)(unaff_ESI + 0x24));
          while (iVar5 == 0) {
            (**(code **)(unaff_ESI + 0x14))(&local_18,8,1,*(undefined4 *)(unaff_ESI + 0x24));
            if (local_18 == 0x61746164) break;
            (**(code **)(unaff_ESI + 0x10))
                      (*(undefined4 *)(unaff_ESI + 0x24),(uStack_14 & 1) + uStack_14,0,1);
            iVar5 = (**(code **)(unaff_ESI + 0x18))(*(undefined4 *)(unaff_ESI + 0x24));
          }
          iVar5 = (**(code **)(unaff_ESI + 0x18))(*(undefined4 *)(unaff_ESI + 0x24));
          if (iVar5 == 0) {
            uVar6 = (**(code **)(unaff_ESI + 0xc))(*(undefined4 *)(unaff_ESI + 0x24));
            *(undefined4 *)(unaff_ESI + 0x30) = uVar6;
            *(uint *)(unaff_ESI + 0x34) = uStack_14;
            *(undefined4 *)(unaff_ESI + 0x450) = *(undefined4 *)(unaff_ESI + 0x40);
            uVar9 = (**(code **)(unaff_ESI + 0xc))(*(undefined4 *)(unaff_ESI + 0x24));
            uStack_8 = (undefined4)uVar9;
            (**(code **)(unaff_ESI + 0x10))
                      (*(undefined4 *)(unaff_ESI + 0x24),(uStack_14 & 1) + uStack_14,0,1);
            iVar5 = (**(code **)(unaff_ESI + 0x18))(*(undefined4 *)(unaff_ESI + 0x24));
            while (iVar5 == 0) {
              (**(code **)(unaff_ESI + 0x14))(&local_18,8,1,*(undefined4 *)(unaff_ESI + 0x24));
              if (local_18 == 0x6c706d73) goto LAB_00596cb0;
              iVar5 = (**(code **)(unaff_ESI + 0x18))(*(undefined4 *)(unaff_ESI + 0x24));
              if (iVar5 != 0) break;
              (**(code **)(unaff_ESI + 0x10))
                        (*(undefined4 *)(unaff_ESI + 0x24),(uStack_14 & 1) + uStack_14,0,1);
              iVar5 = (**(code **)(unaff_ESI + 0x18))(*(undefined4 *)(unaff_ESI + 0x24));
            }
            (**(code **)(unaff_ESI + 0x10))(*(undefined4 *)(unaff_ESI + 0x24),uStack_10,0);
            iVar5 = (**(code **)(unaff_ESI + 0x18))(*(undefined4 *)(unaff_ESI + 0x24));
            while (iVar5 == 0) {
              lVar10 = (**(code **)(unaff_ESI + 0xc))(*(undefined4 *)(unaff_ESI + 0x24));
              if (CONCAT44((int)((ulonglong)uVar9 >> 0x20),uStack_8) <= lVar10) break;
              (**(code **)(unaff_ESI + 0x14))(&local_18,8,1,*(undefined4 *)(unaff_ESI + 0x24));
              if (local_18 == 0x6c706d73) goto LAB_00596cb0;
              iVar5 = (**(code **)(unaff_ESI + 0x18))(*(undefined4 *)(unaff_ESI + 0x24));
              if (iVar5 != 0) break;
              (**(code **)(unaff_ESI + 0x10))
                        (*(undefined4 *)(unaff_ESI + 0x24),(uStack_14 & 1) + uStack_14,0,1);
              iVar5 = (**(code **)(unaff_ESI + 0x18))(*(undefined4 *)(unaff_ESI + 0x24));
            }
LAB_00596d2e:
            (**(code **)(unaff_ESI + 0x10))
                      (*(undefined4 *)(unaff_ESI + 0x24),*(int *)(unaff_ESI + 0x30),
                       *(int *)(unaff_ESI + 0x30) >> 0x1f,0);
            *(undefined4 *)(unaff_ESI + 8) = 0;
            return 0;
          }
        }
      }
    }
  }
  goto LAB_00596ccd;
LAB_00596cb0:
  iVar5 = FUN_0056e030(uStack_14,"..\\..\\..\\..\\Source\\Library\\Main\\DxSoundConvert.cpp",0x261);
  if (iVar5 != 0) {
    (**(code **)(unaff_ESI + 0x14))(iVar5,uStack_14,1,*(undefined4 *)(unaff_ESI + 0x24));
    if (0x17 < uStack_14 - 0x24) {
      *(undefined4 *)(unaff_ESI + 0x56) = *(undefined4 *)(iVar5 + 0x2c);
      *(undefined4 *)(unaff_ESI + 0x5a) = *(undefined4 *)(iVar5 + 0x30);
    }
    FUN_0056e1d0(iVar5);
    goto LAB_00596d2e;
  }
LAB_00596ccd:
  if (*piVar1 != 0) {
    FUN_0056e1d0(*piVar1);
    *piVar1 = 0;
  }
LAB_00596ce2:
  if (psVar8 != (short *)0x0) {
    FUN_0056e1d0(psVar8);
  }
  return 0xffffffff;
}

