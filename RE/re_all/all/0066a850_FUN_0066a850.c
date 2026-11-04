
undefined4
FUN_0066a850(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint param_5)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  
  puVar7 = (undefined1 *)(param_5 + 0x84);
  uVar5 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_5 + 0x80),*(undefined1 *)(param_5 + 0x81)
                                    ),*(undefined1 *)(param_5 + 0x82)),
                   *(undefined1 *)(param_5 + 0x83));
  param_5 = 0;
  if (uVar5 != 0) {
    do {
      uVar8 = CONCAT31(CONCAT21(CONCAT11(*puVar7,puVar7[1]),puVar7[2]),puVar7[3]);
      uVar1 = puVar7[8];
      uVar6 = CONCAT31(CONCAT21(CONCAT11(puVar7[4],puVar7[5]),puVar7[6]),puVar7[7]);
      uVar2 = puVar7[9];
      uVar3 = puVar7[10];
      uVar4 = puVar7[0xb];
      if ((puVar7[7] & 3) != 0) {
        FUN_0066a2d0(param_1,0,param_3,uVar8,s_ICC_profile_tag_start_not_a_mult_00a0c154);
      }
      if ((param_4 < uVar6) ||
         (param_4 - uVar6 < CONCAT31(CONCAT21(CONCAT11(uVar1,uVar2),uVar3),uVar4))) {
        uVar8 = FUN_0066a2d0(param_1,param_2,param_3,uVar8,
                             s_ICC_profile_tag_outside_profile_00a0c134);
        return uVar8;
      }
      puVar7 = puVar7 + 0xc;
      param_5 = param_5 + 1;
    } while (param_5 < uVar5);
  }
  return 1;
}

