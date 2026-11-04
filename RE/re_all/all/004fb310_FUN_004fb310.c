
uint FUN_004fb310(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_18;
  
  if (param_1 == 0) {
    local_18 = 0xffffff9a;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xe0);
    if (iVar1 == 0) {
      local_18 = 0xffffff9a;
    }
    else {
      local_18 = *(uint *)(iVar1 + 0x58) - *(uint *)(iVar1 + 0x60);
      if (param_2 != 0) {
        if ((-(uint)(*(uint *)(iVar1 + 0x58) < *(uint *)(iVar1 + 0x60)) != *(int *)(iVar1 + 100)) ||
           (param_3 <= local_18)) {
          local_18 = param_3;
        }
        if (local_18 == 0) {
          local_18 = 0;
        }
        else {
          iVar2 = FUN_00401750(iVar1 + 0x88,*(undefined4 *)(iVar1 + 0xb4),
                               *(uint *)(iVar1 + 0x50) + *(uint *)(iVar1 + 0x60),
                               *(int *)(iVar1 + 0x54) + *(int *)(iVar1 + 100) +
                               (uint)CARRY4(*(uint *)(iVar1 + 0x50),*(uint *)(iVar1 + 0x60)),0);
          if (iVar2 == 0) {
            uVar3 = (**(code **)(iVar1 + 0x8c))
                              (*(undefined4 *)(iVar1 + 0xa4),*(undefined4 *)(iVar1 + 0xb4),param_2,
                               local_18);
            if (uVar3 != local_18) {
              local_18 = 0xffffffff;
            }
          }
          else {
            local_18 = 0xffffffff;
          }
        }
      }
    }
  }
  return local_18;
}

