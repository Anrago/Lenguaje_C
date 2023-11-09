import cv2

img = cv2.imread('C:\\Users\\PC\\Desktop\\Tilin\\gato.jpg')

if img is not None:
    img2 = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    print("alto, ancho, canales = " + str(img2.shape))

    inverted_img = cv2.bitwise_not(img)

    cv2.imshow('Un gatito GRIS', inverted_img)
    cv2.waitKey()
    cv2.destroyAllWindows()
else:
    print("No se pudo cargar la imagen 'gato.jpg'")