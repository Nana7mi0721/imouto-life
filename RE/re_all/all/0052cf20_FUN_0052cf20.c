
undefined4 FUN_0052cf20(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  int iStack_44;
  undefined1 local_40 [64];
  
  iVar1 = (**(code **)(unaff_ESI + 8))(local_40);
  iVar2 = (**(code **)(unaff_ESI + 0x10))(*(undefined4 *)(unaff_ESI + 0x18));
  while (iVar2 == 0) {
    FUN_0056da20(0);
    iVar2 = (**(code **)(unaff_ESI + 0x10))(*(undefined4 *)(unaff_ESI + 0x18));
  }
  if (iVar1 == 0) {
    return 0;
  }
  iStack_44 = thunk_FUN_00572b40(local_40,param_3);
  if (in_EAX < iStack_44) {
    iVar1 = (**(code **)(unaff_ESI + 8))
                      (local_40 + in_EAX,iStack_44 - in_EAX,1,*(undefined4 *)(unaff_ESI + 0x18));
    iVar2 = (**(code **)(unaff_ESI + 0x10))(*(undefined4 *)(unaff_ESI + 0x18));
    while (iVar2 == 0) {
      FUN_0056da20(0);
      iVar2 = (**(code **)(unaff_ESI + 0x10))(*(undefined4 *)(unaff_ESI + 0x18));
    }
    if (iVar1 == 0) {
      return 0;
    }
  }
  uVar3 = FUN_00572fc0(local_40,param_3,&iStack_44);
  *param_1 = uVar3;
  if (param_2 != (int *)0x0) {
    *param_2 = iStack_44;
  }
  return 1;
}

