
int FUN_00677c50(uint param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_44;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined1 local_38;
  undefined1 local_37;
  
  iVar2 = param_1;
  iVar5 = *(int *)(param_1 + 0x80);
  if (iVar5 != 0) {
    local_3d = (undefined1)param_2;
    local_40 = (undefined1)((uint)param_2 >> 0x18);
    local_3f = (undefined1)((uint)param_2 >> 0x10);
    local_3e = (undefined1)((uint)param_2 >> 8);
    local_3a = (undefined1)((uint)iVar5 >> 0x18);
    local_38 = (undefined1)((uint)iVar5 >> 8);
    local_37 = *(undefined1 *)(param_1 + 0x80);
    local_3c = 0x3a;
    local_3b = 0x20;
    local_39 = (undefined1)((uint)iVar5 >> 0x10);
    FUN_00668650(&local_40,0x40,10,s_using_zstream_00a0cef0);
    FUN_006687b0(param_1,&local_40);
    if (*(int *)(param_1 + 0x80) == 0x49444154) {
      *(char **)(param_1 + 0x9c) = s_in_use_by_IDAT_00a0d4b0;
      return -2;
    }
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  local_44 = *(int *)(param_1 + 0xd0);
  iVar5 = *(int *)(param_1 + 200);
  iVar6 = *(int *)(param_1 + 0xc4);
  iVar7 = *(int *)(param_1 + 0xcc);
  if (param_2 == 0x49444154) {
    if ((*(byte *)(param_1 + 0x78) & 1) == 0) {
      param_1 = (uint)(*(char *)(param_1 + 0x156) != '\b');
    }
    else {
      param_1 = *(uint *)(param_1 + 0xd4);
    }
  }
  else {
    local_44 = *(int *)(param_1 + 0xe4);
    iVar6 = *(int *)(param_1 + 0xd8);
    iVar5 = *(int *)(param_1 + 0xdc);
    iVar7 = *(int *)(param_1 + 0xe0);
    param_1 = *(uint *)(param_1 + 0xe8);
  }
  if (param_3 < 0x4001) {
    for (uVar3 = 1 << ((char)iVar7 - 1U & 0x1f); param_3 + 0x106 <= uVar3; uVar3 = uVar3 >> 1) {
      iVar7 = iVar7 + -1;
    }
  }
  if (((*(byte *)(iVar2 + 0x78) & 2) != 0) &&
     ((((*(int *)(iVar2 + 0xec) != iVar6 || (*(int *)(iVar2 + 0xf0) != iVar5)) ||
       (*(int *)(iVar2 + 0xf4) != iVar7)) ||
      ((*(int *)(iVar2 + 0xf8) != local_44 || (*(uint *)(iVar2 + 0xfc) != param_1)))))) {
    iVar4 = FUN_0067d7a0(iVar2 + 0x84);
    if (iVar4 != 0) {
      FUN_006687b0(iVar2,s_deflateEnd_failed__ignored__00a0d494);
    }
    *(uint *)(iVar2 + 0x78) = *(uint *)(iVar2 + 0x78) & 0xfffffffd;
  }
  puVar1 = (undefined4 *)(iVar2 + 0x84);
  *(undefined4 *)(iVar2 + 0x88) = 0;
  *(undefined4 *)(iVar2 + 0x90) = 0;
  *puVar1 = 0;
  *(undefined4 *)(iVar2 + 0x94) = 0;
  if ((*(byte *)(iVar2 + 0x78) & 2) == 0) {
    iVar5 = FUN_0067cae0(puVar1,iVar6,iVar5,iVar7,local_44,param_1,s_1_2_8_00a0cee8,0x38);
    if (iVar5 == 0) {
      *(int *)(iVar2 + 0x80) = param_2;
      *(uint *)(iVar2 + 0x78) = *(uint *)(iVar2 + 0x78) | 2;
      return 0;
    }
  }
  else {
    iVar5 = FUN_0067cdb0(puVar1);
    if (iVar5 == 0) {
      *(int *)(iVar2 + 0x80) = param_2;
      return 0;
    }
  }
  FUN_00669790(iVar2,iVar5);
  return iVar5;
}

