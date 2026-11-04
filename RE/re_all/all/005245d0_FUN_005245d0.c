
int FUN_005245d0(uint *param_1,int param_2,undefined4 param_3,undefined1 *param_4,int param_5,
                undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint local_478;
  uint local_474;
  uint local_470;
  uint local_46c;
  uint local_468;
  uint local_464;
  uint local_460;
  uint local_45c;
  uint local_458;
  int local_454;
  int local_450;
  int local_44c;
  int local_448;
  int local_444;
  undefined1 local_440 [1088];
  
  local_444 = 0;
  if (((param_2 == 0) && (param_1[0x1c] != 0)) && (param_1[0x1b] == 0)) {
    local_458 = (uint)*(byte *)((int)param_1 + 2);
    local_460 = (uint)*(byte *)((int)param_1 + 1);
    iVar5 = *(int *)(param_4 + 0x42c);
    local_454 = *(int *)(param_4 + 0x428);
    local_45c = *param_1 & 0xff;
    cVar1 = param_4[0xb];
    local_44c = iVar5;
    iVar2 = FUN_00546c90(local_454,iVar5,local_440);
    if (iVar2 == 0) {
      iVar2 = 0;
      if (0 < iVar5) {
        do {
          iVar5 = 0;
          if (0 < local_454) {
            do {
              FUN_00549840(param_4,iVar5,iVar2,&local_464,&local_478,&local_46c,&local_448);
              if (((local_464 == local_458) && (local_478 == local_460)) && (local_46c == local_45c)
                 ) {
                iVar3 = 0;
              }
              else {
                iVar3 = local_448;
                if (cVar1 == '\0') {
                  iVar3 = 0xff;
                }
              }
              FUN_00549610(local_440,iVar5,iVar2,local_464,local_478,local_46c,iVar3);
              iVar5 = iVar5 + 1;
            } while (iVar5 < local_454);
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < local_44c);
        iVar5 = local_44c;
      }
      iVar2 = 0;
      if (0 < iVar5) {
        do {
          iVar5 = 0;
          if (0 < local_454) {
            do {
              FUN_00549840(param_4,iVar5,iVar2,&local_464,&local_478,&local_46c,&local_448);
              if (((local_464 != local_458) || (local_478 != local_460)) || (local_46c != local_45c)
                 ) {
                if (0 < iVar5) {
                  FUN_00549840(param_4,iVar5 + -1,iVar2,&local_468,&local_474,&local_470,&local_450)
                  ;
                  if (((local_468 == local_458) && (local_474 == local_460)) &&
                     (local_470 == local_45c)) {
                    FUN_00549610(local_440,iVar5 + -1,iVar2,local_464,local_478,local_46c,0);
                  }
                }
                if (0 < iVar2) {
                  FUN_00549840(param_4,iVar5,iVar2 + -1,&local_468,&local_474,&local_470,&local_450)
                  ;
                  if (((local_468 == local_458) && (local_474 == local_460)) &&
                     (local_470 == local_45c)) {
                    FUN_00549610(local_440,iVar5,iVar2 + -1,local_464,local_478,local_46c,0);
                  }
                }
                if (iVar5 < local_454 + -1) {
                  FUN_00549840(param_4,iVar5 + 1,iVar2,&local_468,&local_474,&local_470,&local_450);
                  if (((local_468 == local_458) && (local_474 == local_460)) &&
                     (local_470 == local_45c)) {
                    FUN_00549610(local_440,iVar5 + 1,iVar2,local_464,local_478,local_46c,0);
                  }
                }
                if (iVar2 < local_44c + -1) {
                  FUN_00549840(param_4,iVar5,iVar2 + 1,&local_468,&local_474,&local_470,&local_450);
                  if (((local_468 == local_458) && (local_474 == local_460)) &&
                     (local_470 == local_45c)) {
                    FUN_00549610(local_440,iVar5,iVar2 + 1,local_464,local_478,local_46c,0);
                  }
                }
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < local_454);
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < local_44c);
      }
      param_4 = local_440;
      local_444 = 1;
    }
  }
  FUN_00544840(param_4);
  if (param_5 != 0) {
    FUN_00544840(param_5);
  }
  if (param_2 == 0) {
    if (param_1[0x1d] == 1) {
      uVar4 = FUN_00540f50(param_4,0,0);
      *param_1 = uVar4 & 0xffffff;
    }
    iVar5 = FUN_00523550(param_1,param_3,param_4,param_5,param_6,param_7);
    if (iVar5 == -1) goto LAB_00524a4c;
  }
  else {
    iVar5 = FUN_00515880(param_3,&local_448,&local_450);
    if (((iVar5 == -1) || (local_448 != *(int *)(param_4 + 0x428))) ||
       ((local_450 != *(int *)(param_4 + 0x42c) ||
        ((param_5 != 0 &&
         ((local_448 != *(int *)(param_5 + 0x428) || (local_450 != *(int *)(param_5 + 0x42c)))))))))
    {
      return -1;
    }
    if (param_1[0x1d] == 1) {
      uVar4 = FUN_00540f50(param_4,0,0);
      *param_1 = uVar4 & 0xffffff;
    }
    iVar5 = 0;
  }
  FUN_00523c60(param_4,param_5,0,0,param_3,param_1[0x1b] == 0,param_7);
LAB_00524a4c:
  if (local_444 != 0) {
    FUN_005421c0(local_440);
  }
  return iVar5;
}

