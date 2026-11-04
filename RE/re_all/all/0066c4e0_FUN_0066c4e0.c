
void FUN_0066c4e0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar1 = FUN_00669750(param_1,0x49444154);
    if (iVar1 == 0) {
      FUN_00676d70(param_1);
    }
    if ((*(char *)(param_1 + 0x157) == '\x03') &&
       ((int)(uint)*(ushort *)(param_1 + 0x148) < *(int *)(param_1 + 0x14c))) {
      FUN_00668960(param_1,s_Read_palette_index_exceeding_num_00a0c608);
    }
    do {
      iVar2 = FUN_00673070(param_1);
      iVar1 = *(int *)(param_1 + 0x11c);
      if (iVar1 == 0x49454e44) {
        FUN_006735d0(param_1,param_2,iVar2);
      }
      else if (iVar1 == 0x49484452) {
        FUN_00673290(param_1,param_2,iVar2);
      }
      else if (param_2 == 0) {
        FUN_00673140(param_1,iVar2);
      }
      else {
        iVar3 = FUN_00669750(param_1,iVar1);
        if (iVar3 == 0) {
          if (iVar1 == 0x49444154) {
            if ((iVar2 != 0) || ((*(uint *)(param_1 + 0x74) & 0x2000) != 0)) {
              FUN_00668960(param_1,s_Too_many_IDATs_found_00a0c474);
            }
            FUN_00673140(param_1,iVar2);
          }
          else if (iVar1 == 0x504c5445) {
            FUN_00673400(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x624b4744) {
            FUN_00674810(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x6348524d) {
            FUN_006738b0(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x67414d41) {
            FUN_00673620(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x68495354) {
            FUN_00674a10(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x6f464673) {
            FUN_00674c90(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x7043414c) {
            FUN_00674de0(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x7343414c) {
            FUN_00675070(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x70485973) {
            FUN_00674b50(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x73424954) {
            FUN_00673710(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x73524742) {
            FUN_00673a70(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x69434350) {
            FUN_00673b50(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x73504c54) {
            FUN_006742e0(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x74455874) {
            FUN_00675370(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x74494d45) {
            FUN_00675280(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x74524e53) {
            FUN_00674580(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x7a545874) {
            FUN_006754b0(param_1,param_2,iVar2);
          }
          else if (iVar1 == 0x69545874) {
            FUN_006759f0(param_1,param_2,iVar2);
          }
          else {
            FUN_00675c40(param_1,param_2,iVar2,0);
          }
        }
        else {
          if ((iVar1 == 0x49444154) && ((iVar2 != 0 || ((*(uint *)(param_1 + 0x74) & 0x2000) != 0)))
             ) {
            FUN_00668960(param_1,s_Too_many_IDATs_found_00a0c474);
          }
          FUN_00675c40(param_1,param_2,iVar2,iVar3);
          if (iVar1 == 0x504c5445) {
            *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 2;
          }
        }
      }
    } while ((*(byte *)(param_1 + 0x74) & 0x10) == 0);
  }
  return;
}

