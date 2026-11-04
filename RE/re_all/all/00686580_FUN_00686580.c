
uint FUN_00686580(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 in_EAX;
  undefined3 uVar4;
  uint uVar3;
  
  uVar4 = (undefined3)((uint)in_EAX >> 8);
  uVar3 = CONCAT31(uVar4,*(char *)(param_1 + 0x48));
  if (((((((*(char *)(param_1 + 0x48) != '\0') ||
          (uVar3 = CONCAT31(uVar4,*(char *)(param_1 + 0x110)), *(char *)(param_1 + 0x110) != '\0'))
         || (uVar3 = 0, *(int *)(param_1 + 0x28) != 3)) ||
        ((*(int *)(param_1 + 0x24) != 3 || (*(int *)(param_1 + 0x2c) != 2)))) ||
       ((*(int *)(param_1 + 100) != 3 ||
        ((iVar1 = *(int *)(param_1 + 0xc4), *(int *)(iVar1 + 8) != 2 ||
         (uVar3 = 1, *(int *)(iVar1 + 0x60) != 1)))))) || (*(int *)(iVar1 + 0xb8) != 1)) ||
     (((((2 < *(int *)(iVar1 + 0xc) || (*(int *)(iVar1 + 100) != 1)) ||
        (*(int *)(iVar1 + 0xbc) != 1)) ||
       (((iVar2 = *(int *)(param_1 + 0x120), *(int *)(iVar1 + 0x24) != iVar2 ||
         (*(int *)(iVar1 + 0x7c) != iVar2)) ||
        ((*(int *)(iVar1 + 0xd4) != iVar2 ||
         ((iVar2 = *(int *)(param_1 + 0x124), *(int *)(iVar1 + 0x28) != iVar2 ||
          (*(int *)(iVar1 + 0x80) != iVar2)))))))) || (*(int *)(iVar1 + 0xd8) != iVar2)))) {
    uVar3 = uVar3 & 0xffffff00;
  }
  return uVar3;
}

