
void FUN_0066bcd0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return;
  }
  FUN_00672fd0(param_1,param_2);
LAB_0066bcf6:
  uVar3 = FUN_00673070(param_1);
  iVar1 = *(int *)(param_1 + 0x11c);
  uVar2 = *(uint *)(param_1 + 0x74);
  if (iVar1 == 0x49444154) {
    if ((uVar2 & 1) == 0) {
      FUN_00668a30(param_1,s_Missing_IHDR_before_IDAT_00a0c4a8);
    }
    else if ((*(char *)(param_1 + 0x157) == '\x03') && ((uVar2 & 2) == 0)) {
      FUN_00668a30(param_1,s_Missing_PLTE_before_IDAT_00a0c48c);
    }
    else if ((uVar2 & 8) != 0) {
      FUN_00668b90(param_1,s_Too_many_IDATs_found_00a0c474);
    }
    *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 4;
  }
  else {
    if ((uVar2 & 4) != 0) {
      *(uint *)(param_1 + 0x74) = uVar2 | 8;
    }
    if (iVar1 == 0x49484452) {
      FUN_00673290(param_1,param_2,uVar3);
      goto LAB_0066bcf6;
    }
    if (iVar1 == 0x49454e44) {
      FUN_006735d0(param_1,param_2,uVar3);
      goto LAB_0066bcf6;
    }
  }
  iVar4 = FUN_00669750(param_1,iVar1);
  if (iVar4 == 0) {
    if (iVar1 == 0x504c5445) {
      FUN_00673400(param_1,param_2,uVar3);
    }
    else {
      if (iVar1 == 0x49444154) {
        *(undefined4 *)(param_1 + 0x13c) = uVar3;
        return;
      }
      if (iVar1 == 0x624b4744) {
        FUN_00674810(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x6348524d) {
        FUN_006738b0(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x67414d41) {
        FUN_00673620(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x68495354) {
        FUN_00674a10(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x6f464673) {
        FUN_00674c90(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x7043414c) {
        FUN_00674de0(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x7343414c) {
        FUN_00675070(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x70485973) {
        FUN_00674b50(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x73424954) {
        FUN_00673710(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x73524742) {
        FUN_00673a70(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x69434350) {
        FUN_00673b50(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x73504c54) {
        FUN_006742e0(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x74455874) {
        FUN_00675370(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x74494d45) {
        FUN_00675280(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x74524e53) {
        FUN_00674580(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x7a545874) {
        FUN_006754b0(param_1,param_2,uVar3);
      }
      else if (iVar1 == 0x69545874) {
        FUN_006759f0(param_1,param_2,uVar3);
      }
      else {
        FUN_00675c40(param_1,param_2,uVar3,0);
      }
    }
  }
  else {
    FUN_00675c40(param_1,param_2,uVar3,iVar4);
    if (iVar1 == 0x504c5445) {
      *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 2;
    }
    else if (iVar1 == 0x49444154) {
      *(undefined4 *)(param_1 + 0x13c) = 0;
      return;
    }
  }
  goto LAB_0066bcf6;
}

