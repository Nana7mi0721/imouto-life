
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d7680(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 local_200 [8];
  undefined1 auStack_1f8 [504];
  
  if (param_2 == 0) {
    param_1 = param_1 - *(int *)(param_1 + -4);
  }
  if ((*(byte *)(param_1 + 0x16) & 0x20) == 0) {
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    iVar4 = *(int *)(param_1 + 0x2c);
    iVar1 = *(int *)(param_1 + 0x20);
    fVar2 = (float)iVar4;
    if (iVar4 < 0) {
      fVar2 = fVar2 + _DAT_007d4bd8;
    }
    fVar3 = (float)iVar1;
    if (iVar1 < 0) {
      fVar3 = fVar3 + _DAT_007d4bd8;
    }
    FUN_0057a6a0(0x7ffd,0,0x7ffd,DAT_00aba250,local_200,0x200,
                 "\tsize:%10d(%10.3fkb)  user size:%10d(%10.3fkb)  time:%05d  file:%-26s  line:%-6d  ID:%-5d  addr:%08x"
                 ,iVar1,(double)(fVar3 * (float)_DAT_007d7ff0),iVar4,
                 (double)(fVar2 * (float)_DAT_007d7ff0),*(undefined2 *)(param_1 + 0x1c),param_1 + 4,
                 (*(byte *)(param_1 + 0x16) & 3) * 0x10000 + (uint)*(ushort *)(param_1 + 0x1e),
                 (uint)CONCAT12(*(undefined1 *)(param_1 + 0x19),*(undefined2 *)(param_1 + 0x1a)),
                 *(undefined4 *)(param_1 + 0x28));
    uVar5 = 0x10;
    if (*(uint *)(param_1 + 0x2c) < 0x11) {
      uVar5 = *(uint *)(param_1 + 0x2c);
    }
    iVar4 = FUN_005773c0(0x7ffd,local_200);
    puVar6 = *(undefined1 **)(param_1 + 0x28);
    FUN_00576e80(0x7ffd,local_200 + iVar4,"  data:[");
    puVar7 = auStack_1f8 + iVar4;
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      if (DAT_00aba250 == 0) {
        FUN_0057a980();
      }
      FUN_0057a940(0x7ffd,0,0x7ffd,DAT_00aba250,puVar7,"%02x ",*puVar6);
      puVar7 = puVar7 + 3;
      puVar6 = puVar6 + 1;
    }
    FUN_00576e80(0x7ffd,puVar7 + -1,&DAT_008000b4);
    FUN_0056ba10(local_200);
  }
  return;
}

