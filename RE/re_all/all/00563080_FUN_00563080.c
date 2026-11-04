
undefined4 FUN_00563080(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EDI;
  wchar_t *pwVar4;
  undefined4 local_c48;
  int local_c44;
  undefined4 local_c40;
  undefined1 local_c3c [60];
  undefined1 local_c00 [3072];
  
  local_c44 = 0;
  iVar1 = FUN_0057e0e0();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  if ((*(int *)(in_EAX + 0x1c) == *(int *)(in_EAX + 0x24)) &&
     (*(int *)(in_EAX + 0x20) == *(int *)(in_EAX + 0x28))) {
    FUN_00551080(param_1,local_c00);
    iVar1 = FUN_0055ca10(local_c00,&local_c40,&local_c48);
    if (-1 < iVar1) {
      *(undefined4 *)(in_EAX + 0x20) = local_c40;
      *(undefined4 *)(in_EAX + 0x28) = local_c48;
      if (*(int *)(in_EAX + 8) == 0) {
        *(undefined4 *)(in_EAX + 8) = 2;
      }
    }
  }
  if ((*(int *)(in_EAX + 0xc) == 0) && (*(int *)(in_EAX + 0x14) == 0)) {
    if (*(int *)(in_EAX + 8) == 0) {
      iVar2 = FUN_0055ba80(param_1,&local_c44,&local_c48,1);
      iVar1 = local_c44;
      if (iVar2 < 0) {
        pwVar4 = L"Sound File Load Error : %s";
      }
      else {
        iVar2 = FUN_0057e0e0();
        if (iVar2 != 0) {
          if (unaff_EDI != 0) {
            FUN_00580610();
          }
          iVar2 = FUN_00562880();
          if (-1 < iVar2) {
            if (unaff_EDI != 0) {
              FUN_00580f70();
            }
            FUN_0056e1d0(iVar1);
            return 0;
          }
          if (unaff_EDI != 0) {
            FUN_00580f70();
          }
        }
        pwVar4 = L"Sound File Setup Error : %s";
      }
      FUN_0056bc50(pwVar4,param_1);
      if (iVar1 != 0) {
        FUN_0056e1d0(iVar1);
        return 0xffffffff;
      }
    }
    else {
      iVar1 = FUN_00560370();
      if (iVar1 != -1) {
        FUN_00561320();
LAB_005632c0:
        if (*(int *)(in_EAX + 0x1c) != *(int *)(in_EAX + 0x24)) {
          FUN_00562830(*(int *)(in_EAX + 0x1c),*(int *)(in_EAX + 0x24));
          return 0;
        }
        if (*(int *)(in_EAX + 0x20) != *(int *)(in_EAX + 0x28)) {
          FUN_00562540(*(int *)(in_EAX + 0x20),*(int *)(in_EAX + 0x28));
        }
        return 0;
      }
    }
  }
  else {
    FUN_00550fd0(local_c3c);
    uVar3 = FUN_0052eb20();
    iVar1 = FUN_005523f0(local_c3c,param_1,0,0,uVar3);
    if (iVar1 < 0) {
      FUN_0056bc50(L"Sound File Load Error 2 : %s",param_1);
    }
    else {
      iVar2 = FUN_0055eb30();
      if (-1 < iVar2) {
        FUN_005525d0(iVar1);
        goto LAB_005632c0;
      }
      FUN_0056bc50(L"Sound File Setup Error %d : %s",-iVar2,param_1);
    }
    if (-1 < iVar1) {
      FUN_005525d0(iVar1);
    }
  }
  return 0xffffffff;
}

