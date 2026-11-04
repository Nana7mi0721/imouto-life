
undefined4 __thiscall FUN_0056ff20(int param_1,int param_2)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int local_8;
  int local_4;
  
  iVar1 = param_2;
LAB_0056ff30:
  do {
    iVar2 = FUN_00572fc0(in_EAX,*(undefined4 *)(iVar1 + 0x38),&local_8);
    iVar3 = FUN_00572fc0(param_1,*(undefined4 *)(iVar1 + 0x38),&param_2);
    if (iVar2 == 0) {
      if (iVar3 == 0) {
        return 0;
      }
      if (iVar3 == 0x2a) {
        do {
          param_1 = param_1 + param_2;
          iVar2 = FUN_00572fc0(param_1,*(undefined4 *)(iVar1 + 0x38),&param_2);
        } while (iVar2 == 0x2a);
        if (iVar2 == 0) {
          return 0;
        }
      }
      return 0xffffffff;
    }
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    if (iVar3 == 0x2a) {
      do {
        param_1 = param_1 + param_2;
        local_4 = FUN_00572fc0(param_1,*(undefined4 *)(iVar1 + 0x38),&param_2);
      } while (local_4 == 0x2a);
      if (local_4 == 0) {
        return 0;
      }
      while (iVar2 != local_4) {
        in_EAX = in_EAX + local_8;
        iVar2 = FUN_00572fc0(in_EAX,*(undefined4 *)(iVar1 + 0x38),&local_8);
        if (iVar2 == 0) {
          return 0xffffffff;
        }
      }
      if (iVar2 == 0) {
        return 0xffffffff;
      }
    }
    else if (iVar3 != 0x3f) {
      if (iVar3 != iVar2) {
        return 0xffffffff;
      }
      param_1 = param_1 + param_2;
      in_EAX = in_EAX + local_8;
      goto LAB_0056ff30;
    }
    param_1 = param_1 + param_2;
    in_EAX = in_EAX + local_8;
  } while( true );
}

