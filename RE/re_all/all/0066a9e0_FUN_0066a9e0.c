
int FUN_0066a9e0(int param_1,undefined1 *param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  
  iVar6 = 0;
  uVar3 = 0x10000;
  if ((*(byte *)(param_1 + 0x228) & 0x30) == 0x30) {
    return 0;
  }
  iVar4 = 0;
  piVar1 = &DAT_0081e338;
  do {
    if ((((CONCAT31(CONCAT21(CONCAT11(param_2[0x54],param_2[0x55]),param_2[0x56]),param_2[0x57]) ==
           piVar1[-1]) &&
         (CONCAT31(CONCAT21(CONCAT11(param_2[0x58],param_2[0x59]),param_2[0x5a]),param_2[0x5b]) ==
          *piVar1)) &&
        (CONCAT31(CONCAT21(CONCAT11(param_2[0x5c],param_2[0x5d]),param_2[0x5e]),param_2[0x5f]) ==
         piVar1[1])) &&
       (CONCAT31(CONCAT21(CONCAT11(param_2[0x60],param_2[0x61]),param_2[0x62]),param_2[99]) ==
        piVar1[2])) {
      if (iVar6 == 0) {
        iVar6 = CONCAT31(CONCAT21(CONCAT11(*param_2,param_2[1]),param_2[2]),param_2[3]);
        uVar3 = CONCAT31(CONCAT21(CONCAT11(param_2[0x40],param_2[0x41]),param_2[0x42]),param_2[0x43]
                        );
      }
      if ((iVar6 == piVar1[-2]) && (uVar3 == *(ushort *)((int)piVar1 + 0xe))) {
        if (param_3 == 0) {
          uVar2 = FUN_0067c870(0,0,0);
          param_3 = FUN_0067c870(uVar2,param_2,iVar6);
        }
        iVar5 = iVar4 * 0x20;
        if (param_3 != (&DAT_0081e328)[iVar4 * 8]) {
LAB_0066abc3:
          FUN_00668bc0(param_1,s_Not_recognizing_known_sRGB_profi_00a0c180,0);
          return 0;
        }
        uVar2 = FUN_0067c560(0,0,0);
        iVar6 = FUN_0067c560(uVar2,param_2,iVar6);
        if (iVar6 != (&DAT_0081e32c)[iVar4 * 8]) goto LAB_0066abc3;
        if ((&DAT_0081e345)[iVar5] == '\0') {
          if ((&DAT_0081e344)[iVar5] != '\0') goto LAB_0066abb5;
          uVar2 = 0;
          pcVar7 = s_out_of_date_sRGB_profile_with_no_00a0c1b8;
        }
        else {
          uVar2 = 2;
          pcVar7 = s_known_incorrect_sRGB_profile_00a0c1e4;
        }
        FUN_00668bc0(param_1,pcVar7,uVar2);
LAB_0066abb5:
        return (byte)(&DAT_0081e345)[iVar5] + 1;
      }
    }
    piVar1 = piVar1 + 8;
    iVar4 = iVar4 + 1;
    if (&UNK_0081e417 < piVar1) {
      return 0;
    }
  } while( true );
}

