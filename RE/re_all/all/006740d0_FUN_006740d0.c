
int FUN_006740d0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  
  iVar2 = *(int *)(param_1 + 0x80);
  if (iVar2 != 0) {
    local_40 = (undefined1)((uint)iVar2 >> 0x18);
    local_3e = (undefined1)((uint)iVar2 >> 8);
    local_3d = *(undefined1 *)(param_1 + 0x80);
    local_3f = (undefined1)((uint)iVar2 >> 0x10);
    FUN_00668650(&local_40,0x40,4,s_using_zstream_00a0cef0);
    FUN_00668b30(param_1,&local_40);
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  puVar1 = (undefined4 *)(param_1 + 0x84);
  *puVar1 = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  if ((*(byte *)(param_1 + 0x78) & 2) == 0) {
    iVar2 = FUN_0067aba0(puVar1,s_1_2_8_00a0cee8,0x38);
    if (iVar2 == 0) {
      *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 2;
      *(undefined4 *)(param_1 + 0x80) = param_2;
      return 0;
    }
  }
  else {
    iVar2 = FUN_0067aa30(puVar1);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x80) = param_2;
      return 0;
    }
  }
  FUN_00669790(param_1,iVar2);
  return iVar2;
}

