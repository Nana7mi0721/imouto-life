
undefined4 FUN_00537250(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  int local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  uint local_20c;
  undefined4 local_208;
  uint local_204;
  undefined1 local_200 [512];
  
  if (DAT_00cc5c60 == 0) {
    return 0xffffffff;
  }
  iVar7 = DAT_00cc5c98;
  if (DAT_00cc5c98 <= DAT_00cc5c9c) {
    do {
      iVar6 = *(int *)(DAT_00cc5c64 + iVar7 * 4);
      if (iVar6 != 0) {
        local_220 = *(undefined4 *)(iVar6 + 0x93178);
        uVar3 = *(undefined4 *)(iVar6 + 0x93188);
        local_21c = *(int *)(iVar6 + 0x9317c);
        local_218 = *(undefined4 *)(iVar6 + 0x93180);
        local_210 = *(undefined4 *)(iVar6 + 0x93174);
        local_208 = uVar3;
        if (*(int *)(iVar6 + 0x38) == 0) {
          FUN_0056cf70(local_200,0x200,iVar6 + 0x92f60);
          local_214 = *(undefined4 *)(iVar6 + 0x93184);
          local_20c = (uint)*(ushort *)(iVar6 + 0x9316c);
          local_204 = (uint)*(byte *)(iVar6 + 0x93168);
          uVar1 = *(undefined2 *)(iVar6 + 0x93162);
          uVar2 = *(undefined2 *)(iVar6 + 0x93160);
          uVar8 = *(undefined4 *)(iVar6 + 4);
          FUN_00580b80(uVar8);
          local_22c = DAT_00a4b770;
          local_230 = DAT_00a4b768;
          local_234 = DAT_00a4b764;
          local_228 = DAT_00a4b774;
          local_224 = DAT_00a4b778;
          if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
            FUN_0050e770();
          }
          iVar6 = FUN_005809a0(8,0,uVar8);
          if ((iVar6 != -1) &&
             (iVar5 = FUN_0052fdc0(&local_234,iVar6,local_200,uVar1,uVar2,local_20c,local_208,
                                   local_204,0), iVar5 < 0)) {
            FUN_00580b80(iVar6);
          }
        }
        else {
          iVar5 = FUN_0056e030(*(undefined4 *)(iVar6 + 0x40),
                               "..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",0x62e);
          if (iVar5 == 0) {
            FUN_0056bca0(&DAT_007d5c90);
            goto LAB_0053747d;
          }
          FUN_0056d420(iVar5,*(undefined4 *)(iVar6 + 0x3c),*(undefined4 *)(iVar6 + 0x40));
          uVar4 = *(undefined4 *)(iVar6 + 0x40);
          uVar8 = *(undefined4 *)(iVar6 + 4);
          FUN_00580b80(uVar8);
          local_234 = DAT_00a4b764;
          local_22c = DAT_00a4b770;
          local_230 = DAT_00a4b768;
          local_228 = DAT_00a4b774;
          local_224 = DAT_00a4b778;
          FUN_00530620(&local_234,iVar5,uVar4,uVar3,uVar8,0);
          FUN_0056e1d0(iVar5);
        }
        FUN_005309c0(local_220,uVar8);
        if (local_21c != 0) {
          FUN_00530a40(local_218,uVar8);
        }
        FUN_00536620(local_210,uVar8);
      }
LAB_0053747d:
      iVar7 = iVar7 + 1;
    } while (iVar7 <= DAT_00cc5c9c);
  }
  return 0;
}

