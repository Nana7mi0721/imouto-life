
int __fastcall FUN_00604d40(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piStack_6c;
  int *piStack_68;
  int *piStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  int *piStack_1c;
  undefined4 *puStack_c;
  
  iVar3 = *(int *)(param_1 + 0x8c);
  uVar1 = *(uint *)(iVar3 + 0xb0);
  uStack_5c = (int *)(uint)(*(int *)(param_1 + 0x54) != 0);
  if ((uVar1 & 1) == 0) {
    uStack_5c = (int *)((uint)uStack_5c | 2);
  }
  if ((uVar1 & 0x100) == 0) {
    iStack_60 = 0;
  }
  else {
    iStack_60 = iVar3 + 0xc0;
  }
  if ((uVar1 & 0x10) == 0) {
    piStack_64 = (int *)0x0;
  }
  else {
    piStack_64 = (int *)(iVar3 + 0xb8);
  }
  piStack_6c = *(int **)(*(int *)(param_1 + 0x90) + 0x98);
  piStack_68 = &local_48;
  iVar2 = (**(code **)(*piStack_6c + 0x1c))();
  piVar4 = uStack_5c;
  *puStack_c = uStack_5c;
  if (-1 < iVar2) {
    piStack_6c = (int *)((int)register0x00000010 + -0x58);
    iVar2 = (**(code **)*uStack_5c)();
    if (-1 < iVar2) {
      piVar4 = (int *)0x10;
      (**(code **)(*piStack_64 + 0x4c))(piStack_64,0x10,(int)register0x00000010 + -0x50);
      uStack_5c = (int *)0x20;
      uStack_40 = *(undefined4 *)(iVar3 + 0xc4);
      local_48 = *(int *)(iVar3 + 0xbc);
      uStack_44 = *(undefined4 *)(iVar3 + 0xc0);
      (**(code **)(DAT_0085e904 + 0x50))(&DAT_0085e904,0x20,&uStack_5c);
      if ((*(byte *)(iVar3 + 0xb0) & 4) != 0) {
        *(undefined4 *)(param_1 + 0x54) = 0;
      }
      (**(code **)(*piVar4 + 8))(piVar4);
      return 0;
    }
    if ((*(byte *)(iVar3 + 0xb0) & 0x10) != 0) {
      (**(code **)(*piStack_68 + 0x18))(piStack_68,iVar3 + 0xb8,iVar3 + 0xc0);
    }
    if ((*(byte *)(iVar3 + 0xb0) & 1) != 0) {
      (**(code **)(*piStack_68 + 0x20))(piStack_68,1);
    }
    if ((*(byte *)(iVar3 + 0xb0) & 4) != 0) {
      (**(code **)(*piStack_68 + 0x40))(piStack_68,1);
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
    iVar3 = (**(code **)(*piStack_1c + 0x44))(piStack_1c,(int)register0x00000010 + -0x58,&iStack_60)
    ;
    if (iVar3 == 0) {
      (**(code **)(*piVar4 + 0x48))(piVar4,&piStack_64,&piStack_6c);
    }
    iVar2 = 0;
  }
  return iVar2;
}

