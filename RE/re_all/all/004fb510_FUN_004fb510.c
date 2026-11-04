
uint FUN_004fb510(int param_1,undefined1 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint local_c;
  
  if (param_1 == 0) {
    local_c = 0xffffff9a;
  }
  else {
    local_c = param_3;
    if (*(uint *)(param_1 + 0x40) < param_3) {
      local_c = *(uint *)(param_1 + 0x40);
    }
    iVar1 = FUN_00401750(param_1,*(undefined4 *)(param_1 + 0x30),*(uint *)(param_1 + 0x68) + 0x16,
                         *(int *)(param_1 + 0x6c) + (uint)(0xffffffe9 < *(uint *)(param_1 + 0x68)),0
                        );
    if (iVar1 == 0) {
      if (local_c != 0) {
        *param_2 = 0;
        uVar2 = (**(code **)(param_1 + 4))
                          (*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x30),param_2,
                           local_c);
        if (uVar2 != local_c) {
          return 0xffffffff;
        }
      }
      if ((param_2 != (undefined1 *)0x0) && (*(uint *)(param_1 + 0x40) < param_3)) {
        param_2[*(int *)(param_1 + 0x40)] = 0;
      }
    }
    else {
      local_c = 0xffffffff;
    }
  }
  return local_c;
}

