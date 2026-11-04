
void FUN_005d2060(void)

{
  int iVar1;
  int iVar2;
  
  FUN_0056bb10(&PTR_LAB_007ff594);
  iVar1 = DAT_00f3a07c;
  iVar2 = 0;
  if (0 < DAT_00f3a07c) {
    FUN_0056bc50(L"ID3D11Buffer : %d",DAT_00f3a07c);
    iVar2 = iVar1;
  }
  if (0 < DAT_00f3a080) {
    iVar2 = iVar2 + DAT_00f3a080;
    FUN_0056bc50(L"ID3D11Texture1D : %d",DAT_00f3a080);
  }
  if (0 < DAT_00f3a084) {
    iVar2 = iVar2 + DAT_00f3a084;
    FUN_0056bc50(L"ID3D11Texture2D : %d",DAT_00f3a084);
  }
  if (0 < DAT_00f3a088) {
    iVar2 = iVar2 + DAT_00f3a088;
    FUN_0056bc50(L"ID3D11Texture3D : %d",DAT_00f3a088);
  }
  if (0 < DAT_00f3a08c) {
    iVar2 = iVar2 + DAT_00f3a08c;
    FUN_0056bc50(L"ID3D11ShaderResourceView : %d",DAT_00f3a08c);
  }
  if (0 < DAT_00f3a090) {
    iVar2 = iVar2 + DAT_00f3a090;
    FUN_0056bc50(L"ID3D11RenderTargetView : %d",DAT_00f3a090);
  }
  if (0 < DAT_00f3a094) {
    iVar2 = iVar2 + DAT_00f3a094;
    FUN_0056bc50(L"ID3D11DepthStencilView : %d",DAT_00f3a094);
  }
  if (0 < DAT_00f3a098) {
    iVar2 = iVar2 + DAT_00f3a098;
    FUN_0056bc50(L"ID3D11InputLayout : %d",DAT_00f3a098);
  }
  if (0 < DAT_00f3a09c) {
    iVar2 = iVar2 + DAT_00f3a09c;
    FUN_0056bc50(L"ID3D11VertexShader : %d",DAT_00f3a09c);
  }
  if (0 < DAT_00f3a0a0) {
    iVar2 = iVar2 + DAT_00f3a0a0;
    FUN_0056bc50(L"ID3D11PixelShader : %d",DAT_00f3a0a0);
  }
  if (0 < DAT_00f3a0a4) {
    iVar2 = iVar2 + DAT_00f3a0a4;
    FUN_0056bc50(L"ID3D11BlendState : %d",DAT_00f3a0a4);
  }
  if (0 < DAT_00f3a0a8) {
    iVar2 = iVar2 + DAT_00f3a0a8;
    FUN_0056bc50(L"ID3D11DepthStencilState : %d",DAT_00f3a0a8);
  }
  if (0 < DAT_00f3a0ac) {
    iVar2 = iVar2 + DAT_00f3a0ac;
    FUN_0056bc50(L"ID3D11RasterizerState : %d",DAT_00f3a0ac);
  }
  if (0 < DAT_00f3a0b0) {
    iVar2 = iVar2 + DAT_00f3a0b0;
    FUN_0056bc50(L"ID3D11SamplerState : %d",DAT_00f3a0b0);
  }
  FUN_0056bca0(&PTR_LAB_007ff2a8,iVar2);
  return;
}

