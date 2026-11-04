
uint FUN_006bef60(undefined4 *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  
  iVar4 = param_1[3];
  pbVar5 = (byte *)param_1[1];
  uVar6 = param_1[2];
  iVar2 = 0;
  do {
    sVar1 = *(short *)(param_2 + iVar2 * 2);
    if (iVar4 < sVar1) {
      uVar3 = 0x20 - iVar4;
      do {
        if ((byte *)*param_1 <= pbVar5) {
          uVar3 = 0xc0000000;
          break;
        }
        uVar3 = uVar3 - 8;
        uVar6 = uVar6 | (uint)*pbVar5 << ((byte)uVar3 & 0x1f);
        pbVar5 = pbVar5 + 1;
      } while (7 < uVar3);
      iVar4 = 0x20 - uVar3;
    }
    iVar2 = (int)*(short *)(param_2 + 2 + ((uVar6 >> (0x20 - (byte)sVar1 & 0x1f)) + iVar2) * 2);
    if (iVar2 < 1) {
      uVar3 = -iVar2;
      param_1[1] = pbVar5;
      param_1[3] = iVar4 - ((int)uVar3 >> 8);
      param_1[2] = uVar6 << ((byte)(uVar3 >> 8) & 0x1f);
      return uVar3 & 0xff;
    }
    uVar6 = uVar6 << ((byte)sVar1 & 0x1f);
    iVar4 = iVar4 - sVar1;
  } while( true );
}

