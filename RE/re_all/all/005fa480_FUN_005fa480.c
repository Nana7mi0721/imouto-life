
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005fa480(undefined4 *param_1,uint param_2,int param_3,undefined4 param_4,int param_5,
                undefined4 param_6)

{
  uint uVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined2 in_FPUControlWord;
  float10 fVar10;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  uVar1 = param_2;
  puVar8 = param_1;
  (*(code *)param_1[2])(&param_1,1,4,param_2);
  if (((((char)param_1 == 'O') && ((char)((uint)param_1 >> 8) == 'g')) && (param_1._2_1_ == 'g')) &&
     (param_1._3_1_ == 'S')) {
    (*(code *)puVar8[1])(uVar1,0,0,0);
    iVar3 = FUN_0056e030(0x95c,s_D__DxLib_Develop_Source_Library__00a05f80,0xce5);
    if (iVar3 != 0) {
      FUN_0056d380(iVar3,0,0x95c);
      *(int *)(iVar3 + 0x954) = iVar3 + 0x958;
      FUN_0056da30(iVar3);
      *(undefined4 *)(iVar3 + 0x4e0) = 0;
      *(undefined4 *)(iVar3 + 0x4d8) = 0xffffffff;
      *(undefined4 *)(iVar3 + 0x4d4) = 0xffffffff;
      *(undefined4 *)(iVar3 + 0x930) = param_4;
      *(int *)(iVar3 + 0x944) = param_5;
      FUN_006a86a0(iVar3 + 0x26c);
      FUN_006b8810(iVar3 + 0x420);
      FUN_006b89f0(iVar3 + 0x488);
      puVar9 = (undefined4 *)(iVar3 + 0x250);
      for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      *(uint *)(iVar3 + 0x268) = param_2;
      iVar7 = FUN_005fadb0(iVar3);
      if (iVar7 == -1) {
LAB_005faad5:
        FUN_0056dac0(iVar3);
        FUN_005fab40(iVar3);
        return 0;
      }
      FUN_0056da60(iVar3,s_D__DxLib_Develop_Source_Library__00a05f80,0xd0f);
      FUN_006b8aa0(iVar3 + 0x498,iVar3 + 0x420);
      dVar2 = _DAT_00802e18 / ((double)*(uint *)(iVar3 + 0x438) / (double)*(uint *)(iVar3 + 0x43c));
      FUN_006a8cd0(iVar3 + 0x26c);
      FUN_006a8d00(iVar3 + 0x298);
      (**(code **)(iVar3 + 0x254))(*(undefined4 *)(iVar3 + 0x268),0,0,0);
      local_c = 1000;
      iVar7 = FUN_0056e030(16000,s_D__DxLib_Develop_Source_Library__00a05f80,0xd23);
      *(int *)(iVar3 + 0x4b4) = iVar7;
      if (iVar7 == 0) {
        FUN_0056ba10(&DAT_00a05f10);
        FUN_0056dac0(iVar3);
        FUN_005fab40(iVar3);
        return 0;
      }
      *(undefined4 *)(iVar3 + 0x4b8) = 0;
      local_10 = 1000;
      iVar7 = FUN_0056e030(1000,s_D__DxLib_Develop_Source_Library__00a05f80,0xd2d);
      *(int *)(iVar3 + 0x4c0) = iVar7;
      if (iVar7 == 0) {
        FUN_0056ba10(&DAT_00a05ed4);
        FUN_0056dac0(iVar3);
        FUN_005fab40(iVar3);
        return 0;
      }
      local_8 = 1000;
      iVar7 = FUN_0056e030(4000,s_D__DxLib_Develop_Source_Library__00a05f80,0xd36);
      *(int *)(iVar3 + 0x4bc) = iVar7;
      if (iVar7 == 0) {
        FUN_0056ba10(&DAT_00a05e84);
        FUN_0056dac0(iVar3);
        FUN_005fab40(iVar3);
        return 0;
      }
      *(undefined4 *)(iVar3 + 0x4c8) = 0;
      *(undefined4 *)(iVar3 + 0x4cc) = 0;
      *(undefined4 *)(iVar3 + 0x4d0) = 0;
      local_18 = 0;
      iVar7 = 0;
      param_5 = 0;
      param_2 = param_2 & 0xffffff;
      local_14 = 16000;
      do {
        iVar4 = FUN_006a8d90(iVar3 + 0x298,iVar3 + 0x400);
        if (iVar4 != 1) {
          iVar4 = iVar7;
          do {
            iVar7 = FUN_006a8940(iVar3 + 0x26c,iVar3 + 0x288);
            if (iVar7 < 1) {
              iVar5 = FUN_005fad70(iVar3,0x1000);
              iVar7 = iVar4;
              if (iVar5 == 0) {
                **(undefined4 **)(iVar3 + 0x4b4) = 0;
                FUN_0056dac0(iVar3);
                uVar6 = param_6;
                FUN_005fb1b0(iVar3,param_6);
                FUN_0056da60(iVar3,s_D__DxLib_Develop_Source_Library__00a05f80,0xdb3);
                iVar7 = FUN_00546d10(*(undefined4 *)(iVar3 + 0x420),*(undefined4 *)(iVar3 + 0x424),
                                     iVar3 + 0x4ec);
                if (iVar7 == -1) {
                  FUN_0056ba10(&DAT_00a05e38);
                  FUN_0056dac0(iVar3);
                  FUN_005fab40(iVar3);
                  return 0;
                }
                *(undefined4 *)(iVar3 + 0x948) = 0xffffffff;
                *(undefined4 *)(iVar3 + 0x94c) = 0xffffffff;
                *(int *)(iVar3 + 0x4e8) = param_3;
                iVar4 = param_3 * 0x28;
                iVar7 = FUN_0056e030(iVar4,s_D__DxLib_Develop_Source_Library__00a05f80,0xdc4);
                *(int *)(iVar3 + 0x4e4) = iVar7;
                if (iVar7 == 0) {
                  FUN_0056ba10(&DAT_00a05df0);
                  FUN_0056dac0(iVar3);
                  FUN_005fab40(iVar3);
                  return 0;
                }
                FUN_0056d380(iVar7,0,iVar4);
                iVar7 = FUN_0060af30(iVar3);
                if (-1 < iVar7) {
                  FUN_0056dac0(iVar3);
                  FUN_005faf90(iVar3,0);
                  FUN_0056da60(iVar3,s_D__DxLib_Develop_Source_Library__00a05f80,0xdde);
                  *(undefined4 *)(iVar3 + 0x230) = 1;
                  FUN_0056dac0(iVar3);
                  FUN_005fbc30(iVar3,1,1,1,uVar6);
                  return iVar3;
                }
                goto LAB_005faad5;
              }
            }
            else {
              iVar7 = *(int *)(iVar3 + 0x294);
              iVar5 = *(int *)(iVar3 + 0x28c);
              param_2 = CONCAT13(1,(undefined3)param_2);
              FUN_006a89a0(iVar3 + 0x298,iVar3 + 0x288);
              iVar7 = iVar4 + iVar7 + iVar5;
              local_18 = iVar4;
            }
            iVar5 = FUN_006a8d90(iVar3 + 0x298,iVar3 + 0x400);
            iVar4 = iVar7;
          } while (iVar5 != 1);
        }
        iVar4 = FUN_006b89e0(iVar3 + 0x400);
        if (-1 < iVar4) {
          if (-1 < *(int *)(iVar3 + 0x414)) {
            fVar10 = (float10)FUN_006b88c0(iVar3 + 0x498,*(undefined4 *)(iVar3 + 0x410),
                                           *(int *)(iVar3 + 0x414));
            param_4 = CONCAT22(in_FPUControlWord,(undefined2)param_4);
            param_1 = (undefined4 *)(CONCAT22(in_FPUControlWord,param_1._0_2_) | 0xc000000);
            param_5 = (int)ROUND((double)(fVar10 / (float10)dVar2));
          }
          if (param_2._3_1_ != '\0') {
            if (*(int *)(iVar3 + 0x4b8) == local_c) {
              local_c = local_c + 1000;
              local_14 = local_14 + 16000;
              uVar6 = FUN_0056e1b0(*(undefined4 *)(iVar3 + 0x4b4),local_14,
                                   s_D__DxLib_Develop_Source_Library__00a05f80,0xd73);
              *(undefined4 *)(iVar3 + 0x4b4) = uVar6;
            }
            param_2 = param_2 & 0xffffff;
            *(undefined4 *)(*(int *)(iVar3 + 0x4b8) * 0x10 + 4 + *(int *)(iVar3 + 0x4b4)) =
                 *(undefined4 *)(iVar3 + 0x4c8);
            *(int *)(*(int *)(iVar3 + 0x4b8) * 0x10 + *(int *)(iVar3 + 0x4b4)) = local_18;
            *(undefined4 *)(*(int *)(iVar3 + 0x4b8) * 0x10 + 0xc + *(int *)(iVar3 + 0x4b4)) = 0;
            *(undefined4 *)(*(int *)(iVar3 + 0x4b8) * 0x10 + 8 + *(int *)(iVar3 + 0x4b4)) = 0;
            *(int *)(iVar3 + 0x4b8) = *(int *)(iVar3 + 0x4b8) + 1;
          }
          if ((*(int *)(iVar3 + 0x4c8) == local_10) && (*(int *)(iVar3 + 0x4cc) == local_10 >> 0x1f)
             ) {
            local_10 = local_10 + 1000;
            uVar6 = FUN_0056e1b0(*(undefined4 *)(iVar3 + 0x4c0),local_10,
                                 s_D__DxLib_Develop_Source_Library__00a05f80,0xd89);
            *(undefined4 *)(iVar3 + 0x4c0) = uVar6;
          }
          iVar4 = FUN_006b89e0(iVar3 + 0x400);
          if (iVar4 == 1) {
            *(undefined1 *)(*(int *)(iVar3 + 0x4c8) + *(int *)(iVar3 + 0x4c0)) = 1;
          }
          else {
            *(undefined1 *)(*(int *)(iVar3 + 0x4c8) + *(int *)(iVar3 + 0x4c0)) = 0;
          }
          if (*(int *)(iVar3 + 0x4d0) <= param_5) {
            iVar4 = local_8 * 4;
            do {
              if (*(int *)(iVar3 + 0x4d0) == local_8) {
                iVar4 = iVar4 + 4000;
                local_8 = local_8 + 1000;
                uVar6 = FUN_0056e1b0(*(undefined4 *)(iVar3 + 0x4bc),iVar4,
                                     s_D__DxLib_Develop_Source_Library__00a05f80,0xd9b);
                *(undefined4 *)(iVar3 + 0x4bc) = uVar6;
              }
              *(undefined4 *)(*(int *)(iVar3 + 0x4bc) + *(int *)(iVar3 + 0x4d0) * 4) =
                   *(undefined4 *)(iVar3 + 0x4c8);
              *(int *)(iVar3 + 0x4d0) = *(int *)(iVar3 + 0x4d0) + 1;
            } while (*(int *)(iVar3 + 0x4d0) <= param_5);
          }
          uVar1 = *(uint *)(iVar3 + 0x4c8);
          param_5 = param_5 + 1;
          *(uint *)(iVar3 + 0x4c8) = uVar1 + 1;
          iVar4 = *(int *)(iVar3 + 0x4b8) * 0x10;
          *(uint *)(iVar3 + 0x4cc) = *(int *)(iVar3 + 0x4cc) + (uint)(0xfffffffe < uVar1);
          *(int *)(iVar4 + -4 + *(int *)(iVar3 + 0x4b4)) =
               *(int *)(iVar4 + -4 + *(int *)(iVar3 + 0x4b4)) + 1;
        }
      } while( true );
    }
    FUN_0056ba10(&DAT_00a05f44);
  }
  return 0;
}

