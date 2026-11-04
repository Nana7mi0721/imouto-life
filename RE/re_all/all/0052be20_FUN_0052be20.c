
undefined4 FUN_0052be20(void)

{
  int iVar1;
  
  if (DAT_00a37d70 == 1) {
    return 0;
  }
  if ((DAT_00a37e60 == 0) || (DAT_00a37e64 == 0)) {
    DAT_00a37e60 = 0x280;
    DAT_00a37e64 = 0x1e0;
    DAT_00a37e68 = 0x280;
    DAT_00a37e6c = 0x1e0;
    FUN_00584ed0(0x280,0x1e0);
  }
  if (DAT_00a37e70 == 0) {
    DAT_00a37e70 = 0x10;
    FUN_005811a0(0);
  }
  FUN_005808a0(1,0x26c,0x8000,&LAB_00517870,&LAB_0052ab30,L"Graph");
  FUN_005808a0(0xc,0x4c,0x1000,&LAB_0051c630,&LAB_0051c640,L"Shader");
  FUN_005808a0(0x13,0x3c,0x2000,&LAB_0051c750,&LAB_0051c760,L"ShaderConstantBuffer");
  FUN_005808a0(0xf,0x48,0x4000,&LAB_0051c780,&LAB_0051c770,L"VertexBuffer");
  FUN_005808a0(0x10,0x48,0x4000,&LAB_0051c780,&LAB_0051c770,L"IndexBuffer");
  FUN_005808a0(0x12,0x46c,0x2000,FUN_0052bcf0,&LAB_0052bda0,L"ShadowMap");
  iVar1 = FUN_00567940();
  if (-1 < iVar1) {
    DAT_00a37d70 = 1;
    if (DAT_00a37d78 == 1) {
      FUN_005679e0();
    }
    else {
      FUN_00515170();
    }
    FUN_0052ade0();
    FUN_005810a0();
    FUN_00536f90();
    FUN_0057b020();
    iVar1 = FUN_005679b0();
    if (-1 < iVar1) {
      return 0;
    }
  }
  FUN_005222f0();
  return 0xffffffff;
}

