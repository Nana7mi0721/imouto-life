
uint FUN_005fbab0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar3 = param_1;
  iVar1 = 0;
  local_4 = -1;
  if (0 < param_2) {
    iVar2 = -1;
    do {
      iVar4 = iVar2;
      if (*(char *)(*(int *)(param_1 + 0x4dc) + *(int *)(param_1 + 0x4c0) + iVar1) == '\x01') {
        iVar4 = *(int *)(param_1 + 0x4dc) + iVar1;
        local_4 = iVar2;
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar4;
    } while (iVar1 < param_2);
  }
  param_1 = 0;
  if (0 < param_2) {
    iVar1 = iVar3 + 0x298;
    do {
      do {
        iVar2 = FUN_006a8d90(iVar1,iVar3 + 0x400);
        if (iVar2 != 1) {
          do {
            iVar2 = FUN_006a8940(iVar3 + 0x26c,iVar3 + 0x288);
            if (iVar2 < 1) {
              iVar2 = (**(code **)(iVar3 + 0x25c))(*(undefined4 *)(iVar3 + 0x268));
              if (iVar2 != 0) {
                return 0xffffffff;
              }
              FUN_005fad70(iVar3,0x1000);
            }
            else {
              FUN_006a89a0(iVar1,iVar3 + 0x288);
            }
            iVar2 = FUN_006a8d90(iVar1,iVar3 + 0x400);
          } while (iVar2 != 1);
        }
        if ((local_4 == -1) || (local_4 <= *(int *)(iVar3 + 0x4dc))) {
          FUN_006b8cd0(iVar3 + 0x498,iVar3 + 0x400);
        }
        iVar2 = FUN_006b89e0(iVar3 + 0x400);
      } while (iVar2 < 0);
      if (-1 < *(int *)(iVar3 + 0x414)) {
        FUN_006b8890(iVar3 + 0x498,5,iVar3 + 0x410,8);
      }
      *(int *)(iVar3 + 0x4dc) = *(int *)(iVar3 + 0x4dc) + 1;
      param_1 = param_1 + 1;
    } while (param_1 < param_2);
  }
  iVar3 = FUN_006b89e0(iVar3 + 0x400);
  return (uint)(iVar3 == 1);
}

