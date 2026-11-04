
undefined4 FUN_0055c8c0(void)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  int iVar4;
  int *piVar5;
  undefined2 *local_10;
  uint local_c;
  uint local_8;
  undefined2 *local_4;
  
  iVar4 = in_EAX * 0x1dc;
  piVar5 = &DAT_00a83cb8 + in_EAX * 0x77;
  iVar1 = FUN_005518a0(piVar5,(&DAT_00a83e70)[in_EAX * 0x77] * 2,0x2b10,&local_4,&local_8,&local_10,
                       &local_c);
  if (iVar1 != 0) {
    FUN_0056bb10(&DAT_007d6468);
    return 0xffffffff;
  }
  uVar2 = local_8 >> 1;
  if (uVar2 != 0) {
    puVar3 = local_4;
    do {
      *puVar3 = *(undefined2 *)
                 ((&DAT_00a83e7c)[in_EAX * 0x77] + *(int *)(&DAT_00a83e74 + iVar4) * 2);
      (&DAT_00a83e70)[in_EAX * 0x77] = (&DAT_00a83e70)[in_EAX * 0x77] + 1;
      puVar3 = puVar3 + 1;
      if ((&DAT_00a83e70)[in_EAX * 0x77] == 0x5622) {
        (&DAT_00a83e70)[in_EAX * 0x77] = 0;
      }
      *(int *)(&DAT_00a83e74 + iVar4) = *(int *)(&DAT_00a83e74 + iVar4) + 1;
      if (*(int *)(&DAT_00a83e74 + iVar4) == *(int *)(&DAT_00a83e78 + iVar4)) {
        *(undefined4 *)(&DAT_00a83e74 + iVar4) = 0;
      }
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  if ((local_10 != (undefined2 *)0x0) && (uVar2 = local_c >> 1, uVar2 != 0)) {
    puVar3 = local_10;
    do {
      *puVar3 = *(undefined2 *)
                 ((&DAT_00a83e7c)[in_EAX * 0x77] + *(int *)(&DAT_00a83e74 + iVar4) * 2);
      (&DAT_00a83e70)[in_EAX * 0x77] = (&DAT_00a83e70)[in_EAX * 0x77] + 1;
      puVar3 = puVar3 + 1;
      if ((&DAT_00a83e70)[in_EAX * 0x77] == 0x5622) {
        (&DAT_00a83e70)[in_EAX * 0x77] = 0;
      }
      *(int *)(&DAT_00a83e74 + iVar4) = *(int *)(&DAT_00a83e74 + iVar4) + 1;
      if (*(int *)(&DAT_00a83e74 + iVar4) == *(int *)(&DAT_00a83e78 + iVar4)) {
        *(undefined4 *)(&DAT_00a83e74 + iVar4) = 0;
      }
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  if ((*piVar5 != 0) && (DAT_00a83c64 == 0)) {
    FUN_0057e820(piVar5,local_4,local_8,local_10,local_c);
  }
  return 0;
}

